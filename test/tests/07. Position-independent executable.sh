#!/bin/bash



###########################################################################################
#    PARAMETERS
###########################################################################################



WORKING_DIR=`pwd`
BUILD_CONFIG=include/buildconfig.h
BUILD_LOG=/tmp/ngos_test.log
BUILD_CFG_BACKUP=/tmp/ngos_test_buildconfig2.h
TEMP_LOG=/tmp/ngos_kernel.log
GDB_FIFO=/tmp/ngos_gdb_fifo
GDB_LOG=/tmp/ngos_gdb.log
MEMORY_DUMP=/tmp/ngos_memory.dmp
EXPECTED_MEMORY_DUMP=assets/PIE_memory.dmp.hex
VM_NAME="NGOS_dev"



###########################################################################################
#    PROCESSING
###########################################################################################



echo -e "\e[36m==================================================\e[0m"
echo -e "\e[36m                     Test: PIE\e[0m"
echo -e "\e[36m==================================================\e[0m"



echo ""
echo -e "\e[33m-------------------- Building --------------------\e[0m"
echo ""



cd ../../
cp ${BUILD_CONFIG} ${BUILD_CFG_BACKUP}

tools/qt/build_config_maker/build/build_config_maker ${BUILD_CONFIG} NGOS_BUILD_X86_64_VECTORIZATION_MODE=OPTION_X86_64_VECTORIZATION_MODE_NONE NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD=OPTION_X86_64_FUSED_MULTIPLY_ADD_NONE > ${BUILD_LOG} 2>&1
make test-debug >> ${BUILD_LOG} 2>&1

if [ $? -ne 0 ]; then
    cp ${BUILD_CFG_BACKUP} ${BUILD_CONFIG}

    cat ${BUILD_LOG} 2>&1
    exit 1
fi

cp ${BUILD_CFG_BACKUP} ${BUILD_CONFIG}
cd ${WORKING_DIR}/



echo ""
echo -e "\e[33m-------------- Checking for GOTPCREL -------------\e[0m"
echo ""



GOTPCREL_SEARCH=`grep -r GOTPCREL ../../src/os/configure/ | grep -v ^Binary | grep -v procesself.o`

if [ "${GOTPCREL_SEARCH}" != "" ]; then
    echo "${GOTPCREL_SEARCH}"
    echo "GOTPCREL found in asm code"

    exit 1
fi



echo ""
echo -e "\e[33m------------------ Starting QEMU -----------------\e[0m"
echo ""



cd ../../tools/vm
./start_vm.sh qemu none > ${TEMP_LOG} 2>&1 &
cd ${WORKING_DIR}/



echo ""
echo -e "\e[33m------------------ Starting GDB ------------------\e[0m"
echo ""



rm ${GDB_FIFO} 2> /dev/null
mkfifo ${GDB_FIFO}

tail -f ${GDB_FIFO} | gdb > ${GDB_LOG} 2>&1 &



echo ""
echo -e "\e[33m-------------- Waiting for GDB debug -------------\e[0m"
echo ""



echo "(gdb) set architecture i386:x86-64:intel"
echo "set architecture i386:x86-64:intel" > ${GDB_FIFO}
#sleep 1



while true
do
    GDB_READY=`grep "gdb_debug is ready to go" ${TEMP_LOG} | head -n 1`

    if [ "${GDB_READY}" != "" ]; then
        break
    fi

    sleep 1
done



echo "${GDB_READY}"



echo "(gdb) target remote :1234"
echo "target remote :1234" > ${GDB_FIFO}
#sleep 1



echo ""
echo -e "\e[33m------------ Breakpoint initialization -----------\e[0m"
echo ""



KERNEL_LOCATION=`grep "Kernel started at address" ${TEMP_LOG} | head -n 1`
echo "${KERNEL_LOCATION}"
KERNEL_LOCATION=`echo "${KERNEL_LOCATION}" | cut -c 38-`



echo "(gdb) x/50i ${KERNEL_LOCATION}"
echo "x/50i ${KERNEL_LOCATION}" > ${GDB_FIFO}
sleep 1



while true
do
    JUMP_TO_RELOCATION_ADDRESS=`tail -n 50 ${GDB_LOG} | grep "jmpq   \*%rax" | head -n 1`

    if [ "${JUMP_TO_RELOCATION_ADDRESS}" != "" ]; then
        break
    fi

    sleep 1
done



echo "${JUMP_TO_RELOCATION_ADDRESS}"
JUMP_TO_RELOCATION_ADDRESS=`echo "${JUMP_TO_RELOCATION_ADDRESS}" | cut -d : -f 1 | cut -c 6-`



echo "(gdb) br *0x${JUMP_TO_RELOCATION_ADDRESS}"
echo "br *0x${JUMP_TO_RELOCATION_ADDRESS}" > ${GDB_FIFO}
#sleep 1

echo "(gdb) continue"
echo "continue" > ${GDB_FIFO}
#sleep 1



while true
do
    BREAKPOINT=`tail -n 5 ${GDB_LOG} | grep "${JUMP_TO_RELOCATION_ADDRESS}" | grep " in " | head -n 1`

    if [ "${BREAKPOINT}" != "" ]; then
        break
    fi

    sleep 1
done



echo "${BREAKPOINT}"



echo "(gdb) nexti"
echo "nexti" > ${GDB_FIFO}
#sleep 1

echo "(gdb) x/50i \$pc"
echo "x/50i \$pc" > ${GDB_FIFO}
sleep 1



OLD_RELOCATION_ADDRESS=${JUMP_TO_RELOCATION_ADDRESS}

while true
do
    JUMP_TO_RELOCATION_ADDRESS=`tail -n 50 ${GDB_LOG} | grep "jmpq   \*%rax" | grep -v "${OLD_RELOCATION_ADDRESS}" | head -n 1`

    if [ "${JUMP_TO_RELOCATION_ADDRESS}" != "" ]; then
        break
    fi

    sleep 1
done



echo "${JUMP_TO_RELOCATION_ADDRESS}"
JUMP_TO_RELOCATION_ADDRESS=`echo "${JUMP_TO_RELOCATION_ADDRESS}" | cut -d : -f 1 | cut -c 6-`



echo "(gdb) br *0x${JUMP_TO_RELOCATION_ADDRESS}"
echo "br *0x${JUMP_TO_RELOCATION_ADDRESS}" > ${GDB_FIFO}
#sleep 1

echo "(gdb) continue"
echo "continue" > ${GDB_FIFO}
#sleep 1



while true
do
    BREAKPOINT=`tail -n 5 ${GDB_LOG} | grep "${JUMP_TO_RELOCATION_ADDRESS}" | grep " in " | head -n 1`

    if [ "${BREAKPOINT}" != "" ]; then
        break
    fi

    sleep 1
done



echo "${BREAKPOINT}"



echo ""
echo -e "\e[33m----------------- Dumping memory -----------------\e[0m"
echo ""



echo "(gdb) dump binary memory ${MEMORY_DUMP} 0 0x000A0000"
echo "dump binary memory ${MEMORY_DUMP} 0 0x000A0000" > ${GDB_FIFO}
sleep 10

hexdump -C ${MEMORY_DUMP} | grep -v "^00001" | grep -v "^0009f" | grep -v "^\*$" > ${MEMORY_DUMP}.hex



echo ""
echo -e "\e[33m------------------- Killing GDB ------------------\e[0m"
echo ""



echo "(gdb) quit"
echo "quit" > ${GDB_FIFO}
#sleep 1

echo "(gdb) y"
echo "y" > ${GDB_FIFO}
#sleep 1

GDB_LOGGER_PID=`ps -ef | grep "tail -f ${GDB_FIFO}" | grep -v grep | awk '{print $2}'`
kill -9 ${GDB_LOGGER_PID} > /dev/null 2>&1



echo ""
echo -e "\e[33m------------------ Killing QEMU ------------------\e[0m"
echo ""



sudo virsh destroy  "${VM_NAME}"         2> /dev/null
sudo virsh undefine "${VM_NAME}" --nvram 2> /dev/null



echo ""
echo -e "\e[33m----------------- Checking result ----------------\e[0m"
echo ""



diff ${MEMORY_DUMP}.hex ${EXPECTED_MEMORY_DUMP}

if [ $? -ne 0 ]; then
    echo "Memory dumps are different"

    exit 1
fi

echo "OK"



exit 0
