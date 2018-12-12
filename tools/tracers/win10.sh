#!/bin/bash

# This script helps to trace over all win10 kernel instructions
# Author: Maxim Shvecov
# Usage: ./win10.sh



###########################################################################################
#    PARAMETERS
###########################################################################################



OS_NAME=win10

WORKING_DIR=`pwd`
TEMP_LOG=/tmp/${OS_NAME}_kernel.log
GDB_FIFO=/tmp/${OS_NAME}_gdb_fifo
GDB_LOG=/tmp/${OS_NAME}_gdb.log
LAST_BREAKPOINT_FILE=/tmp/${OS_NAME}_breakpoint.txt
LAST_REGISTERS_FILE=/tmp/${OS_NAME}_registers.txt
OUTPUT_FILE=/tmp/${OS_NAME}_tracer.txt

INITIAL_BREAKPOINT=0x3FFA1CCD



NEXTI_FILTERS=(
    -E
    -e "placeholder123456789"
)

NEXT_FILTERS=(
    -E
    -e "rep \w+"
)

FINISH_FILTERS=(
    -E
    -e "placeholder123456789"
)



###########################################################################################
#    FUNCTIONS
###########################################################################################



function execute_gdb_command()
{
    COMMAND=$1
    VERBOSE=$2

    COMMAND_ID=`date +%s%N`



    if [ "${VERBOSE}" == "-v" ]; then
        echo "(gdb) ${COMMAND}"
    fi

    echo "echo ${COMMAND}\n"                   > ${GDB_FIFO}
    echo "echo >>>>>>>> BEGIN ${COMMAND_ID}\n" > ${GDB_FIFO}
    echo "${COMMAND}"                          > ${GDB_FIFO}
    echo "echo <<<<<<<< END ${COMMAND_ID}\n"   > ${GDB_FIFO}



    while true
    do
        END_INDEX=`grep -a -n -m 1 "<<<<<<<< END ${COMMAND_ID}" ${GDB_LOG} | cut -d : -f 1`

        if [ "${END_INDEX}" != "" ]; then
            break
        fi
    done

    START_INDEX=`grep -a -n -m 1 ">>>>>>>> BEGIN ${COMMAND_ID}" ${GDB_LOG} | cut -d : -f 1`



    END_INDEX=$((${END_INDEX} - 1))
    LINE_COUNT=$((${END_INDEX} - ${START_INDEX}))



    head -n ${END_INDEX} ${GDB_LOG} | tail -n ${LINE_COUNT} | sed "s/(gdb) //g"
    truncate -s 0 ${GDB_LOG}
}



###########################################################################################
#    PROCESSING
###########################################################################################



echo -e "\e[36m==================================================\e[0m"
echo -e "\e[36m                 Windows 10 tracer\e[0m"
echo -e "\e[36m==================================================\e[0m"



if [ "`pwd | grep tools/tracers`" == "" -o ! -f ${OS_NAME}.sh ]; then
    echo "Please run this script from the script local folder"
    exit 1
fi



echo ""
echo -e "\e[33m----------------- Initialization -----------------\e[0m"
echo ""



cd ../../tools/gdb
./install.sh
cd ${WORKING_DIR}/



echo ""
echo -e "\e[33m------------------ Starting QEMU -----------------\e[0m"
echo ""



cd ../../tools/vm
./start_vm.sh qemu none ${OS_NAME} > ${TEMP_LOG} 2>&1 &
cd ${WORKING_DIR}/



echo ""
echo -e "\e[33m------------------ Starting GDB ------------------\e[0m"
echo ""



GDB_LOGGER_PID=`ps -ef | grep "tail -f ${GDB_FIFO}" | grep -v grep | awk '{print $2}'`
kill -9 ${GDB_LOGGER_PID} > /dev/null 2>&1



rm ${GDB_FIFO} 2> /dev/null
mkfifo ${GDB_FIFO}

tail -f ${GDB_FIFO} | gdb >> ${GDB_LOG} 2>&1 &



echo ""
echo -e "\e[33m-------------- Waiting for GDB debug -------------\e[0m"
echo ""



sleep 5
execute_gdb_command "set width 200" -v
execute_gdb_command "set listsize 1" -v
execute_gdb_command "set architecture i386:x86-64:intel" -v
execute_gdb_command "target remote :1234" -v



BREAKPOINT=`cat ${LAST_BREAKPOINT_FILE} 2> /dev/null`

if [ "${BREAKPOINT}" != "" ]; then
    execute_gdb_command "tbreak *${BREAKPOINT}" -v
    execute_gdb_command "continue" -v

    echo ""                       >> ${OUTPUT_FILE}
    echo "Terminated. Continuing" >> ${OUTPUT_FILE}
    echo ""                       >> ${OUTPUT_FILE}
else
    rm ${LAST_BREAKPOINT_FILE}     > /dev/null 2>&1
    rm ${LAST_REGISTERS_FILE}      > /dev/null 2>&1
    rm ${LAST_REGISTERS_FILE}.tmp  > /dev/null 2>&1
    rm ${OUTPUT_FILE}              > /dev/null 2>&1

    execute_gdb_command "tbreak *${INITIAL_BREAKPOINT}" -v
    execute_gdb_command "continue" -v

    execute_gdb_command "info all-registers" | grep -v "rip" > ${LAST_REGISTERS_FILE}
fi



while true
do
    INSTRUCTION=`execute_gdb_command "x/i \\\$pc"`
    echo -ne "\r\033[K${INSTRUCTION}"

    INSTRUCTION_ADDRESS_NICE=`echo "${INSTRUCTION}" | cut -d : -f 1 | cut -c 4-`
    INSTRUCTION_ADDRESS=`echo "${INSTRUCTION_ADDRESS_NICE}" | cut -d \< -f 1`
    INSTRUCTION=`echo "${INSTRUCTION}" | cut -d : -f 2`

    echo "${INSTRUCTION_ADDRESS}" >  ${LAST_BREAKPOINT_FILE}



    MEMORY_LOCATIONS=(`echo "${INSTRUCTION}" | grep -o -E -e "\*?(0x[0-9a-f]+)?\((%.{2,3})\)" -e "# +(0x[0-9a-f]+)" -e "\*(%.{2,3})" | sed -r "s/^# +//g"`)
    MEMORY_VALUES_BEFORE=()

    for LOCATION in "${MEMORY_LOCATIONS[@]}"
    do
        IS_LOCATION_POINTER=`echo "${LOCATION}" | grep -E -e "\*(0x[0-9a-f]+)?\((%.{2,3})\)"`

        if [ "${IS_LOCATION_POINTER}" != "" ]; then
            MEMORY_DUMP_ARG=`echo "${LOCATION}" | sed -r "s/(\*)(0x[0-9a-f]+)?\((%.{2,3})\)/\2 + \3/g" | sed -r "s/^ \+ //g" | sed -r "s/%/\$/g"`
            MEMORY_DUMP_ARG=`execute_gdb_command "x/1xg ${MEMORY_DUMP_ARG}" | cut -d : -f 2 | cut -c 2-`
        else
            MEMORY_DUMP_ARG=`echo "${LOCATION}" | sed -r "s/(0x[0-9a-f]+)?\((%.{2,3})\)/\1 + \2/g" | sed -r "s/^( \+ |\*)//g" | sed -r "s/%/\$/g"`
        fi

        MEMORY_VALUE=`execute_gdb_command "x/1xg ${MEMORY_DUMP_ARG}"`
        MEMORY_VALUES_BEFORE+=("${MEMORY_VALUE}")
    done



    SOURCE_LINE=`execute_gdb_command "list *${INSTRUCTION_ADDRESS}"`



    IGNORED="Ignored."
    FILTERING_DATA="${INSTRUCTION_ADDRESS_NICE} ${INSTRUCTION} ${MEMORY_VALUES_BEFORE[@]} ${SOURCE_LINE}"

    if [ "`echo "${FILTERING_DATA}" | grep "${NEXTI_FILTERS[@]}"`" != "" ]; then
        execute_gdb_command "nexti" > /dev/null 2>&1
    elif [ "`echo "${FILTERING_DATA}" | grep "${NEXT_FILTERS[@]}"`" != "" ]; then
        NEXT_INSTRUCTION=`execute_gdb_command "x/2i \\\$pc" | tail -n 1`
        NEXT_INSTRUCTION_ADDRESS_NICE=`echo "${NEXT_INSTRUCTION}" | cut -d : -f 1 | cut -c 4-`
        NEXT_INSTRUCTION_ADDRESS=`echo "${NEXT_INSTRUCTION_ADDRESS_NICE}" | cut -d \< -f 1`

        execute_gdb_command "tbreak *${NEXT_INSTRUCTION_ADDRESS}" > /dev/null 2>&1
        execute_gdb_command "continue" > /dev/null 2>&1
    elif [ "`echo "${FILTERING_DATA}" | grep "${FINISH_FILTERS[@]}"`" != "" ]; then
        execute_gdb_command "finish" > /dev/null 2>&1
    else
        IGNORED=
        execute_gdb_command "stepi" > /dev/null 2>&1
    fi



    MEMORY_VALUES_AFTER=()

    for LOCATION in "${MEMORY_LOCATIONS[@]}"
    do
        IS_LOCATION_POINTER=`echo "${LOCATION}" | grep -E -e "\*(0x[0-9a-f]+)?\((%.{2,3})\)"`

        if [ "${IS_LOCATION_POINTER}" != "" ]; then
            MEMORY_DUMP_ARG=`echo "${LOCATION}" | sed -r "s/(\*)(0x[0-9a-f]+)?\((%.{2,3})\)/\2 + \3/g" | sed -r "s/^ \+ //g" | sed -r "s/%/\$/g"`
            MEMORY_DUMP_ARG=`execute_gdb_command "x/1xg ${MEMORY_DUMP_ARG}" | cut -d : -f 2 | cut -c 2-`
        else
            MEMORY_DUMP_ARG=`echo "${LOCATION}" | sed -r "s/(0x[0-9a-f]+)?\((%.{2,3})\)/\1 + \2/g" | sed -r "s/^( \+ |\*)//g" | sed -r "s/%/\$/g"`
        fi

        MEMORY_VALUE=`execute_gdb_command "x/1xg ${MEMORY_DUMP_ARG}"`
        MEMORY_VALUES_AFTER+=("${MEMORY_VALUE}")
    done



    MEMORY_CHANGES=
    MEMORY_COUNT=${#MEMORY_LOCATIONS[*]}

    for ((i = 0; i < ${MEMORY_COUNT}; i++))
    do
        LOCATION=${MEMORY_LOCATIONS[$i]}
        VALUE_BEFORE=${MEMORY_VALUES_BEFORE[$i]}
        VALUE_AFTER=${MEMORY_VALUES_AFTER[$i]}

        LOCATION_BEFORE=`echo "${VALUE_BEFORE}" | cut -d : -f 1`
        LOCATION_AFTER=`echo "${VALUE_AFTER}" | cut -d : -f 1`

        if [ "${LOCATION_BEFORE}" == "${LOCATION_AFTER}" ]; then
            if [ "${MEMORY_CHANGES}" != "" ]; then
                MEMORY_CHANGES+=", "
            fi

            VALUE_BEFORE=`echo "${VALUE_BEFORE}" | cut -d : -f 2 | cut -c 2-`
            VALUE_AFTER=`echo "${VALUE_AFTER}" | cut -d : -f 2 | cut -c 2-`

            if [ "${LOCATION}" != "${LOCATION_BEFORE}" ]; then
                MEMORY_CHANGES+="${LOCATION} == "
            fi

            MEMORY_CHANGES+="${LOCATION_BEFORE}: ${VALUE_BEFORE}"

            if [ "${VALUE_BEFORE}" != "${VALUE_AFTER}" ]; then
                MEMORY_CHANGES+=" => ${VALUE_AFTER}"
            fi
        fi
    done



    execute_gdb_command "info all-registers" | grep -v "rip" > ${LAST_REGISTERS_FILE}.tmp

    REGISTERS_DIFF=`diff --changed-group-format="%<%>" --unchanged-group-format="" --old-line-format="%l => " --new-line-format="%l ; " ${LAST_REGISTERS_FILE} ${LAST_REGISTERS_FILE}.tmp`



    if [ "${IGNORED}" != "" ]; then
        DETAILS="${IGNORED} ${MEMORY_CHANGES}"
    else
        DETAILS="${MEMORY_CHANGES}"
    fi



    RESULT_LINE=`printf "%-60s:%-60s // %-80s // %-100s // %s\n" "${INSTRUCTION_ADDRESS_NICE}" "${INSTRUCTION}" "${DETAILS}" "${REGISTERS_DIFF}" "${SOURCE_LINE}"`
    echo "${RESULT_LINE}" >> ${OUTPUT_FILE}



    mv ${LAST_REGISTERS_FILE}.tmp ${LAST_REGISTERS_FILE}
done



exit 0
