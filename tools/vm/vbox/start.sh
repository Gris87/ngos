#!/bin/bash
                                                                                                                                                                                                         # Colorize: green
# This script helps to start VM                                                                                                                                                                          # Colorize: green
# Author: Maxim Shvecov                                                                                                                                                                                  # Colorize: green
# Usage: ./start.sh RAM_SIZE HDD_SIZE [DISPLAY_TYPE] [OS_TYPE]                                                                                                                                                    # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
#    PARAMETERS                                                                                                                                                                                          # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
CURRENT_PATH=`pwd`                                                                                                                                                                                       # Colorize: green
TTY=/tmp/ngos_ttyS0_vbox                                                                                                                                                                                  # Colorize: green
VM_NAME="NGOS_dev"                                                                                                                                                                                       # Colorize: green
RAM_SIZE=$1                                                                                                                                                                                              # Colorize: green
HDD_SIZE=$2                                                                                                                                                                                              # Colorize: green
DISPLAY_TYPE=$3                                                                                                                                                                                          # Colorize: green
OS_TYPE=$4                                                                                                                                                                                               # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
#    VERIFICATION                                                                                                                                                                                        # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
if [ "${RAM_SIZE}" == "" ]; then                                                                                                                                                                         # Colorize: green
    echo "Please specify RAM size."                                                                                                                                                                      # Colorize: green
    echo "    Usage: ./start.sh RAM_SIZE HDD_SIZE [DISPLAY_TYPE] [OS_TYPE]"                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    exit 1                                                                                                                                                                                               # Colorize: green
fi                                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
if [ "${HDD_SIZE}" == "" ]; then                                                                                                                                                                         # Colorize: green
    echo "Please specify HDD size."                                                                                                                                                                      # Colorize: green
    echo "    Usage: ./start.sh RAM_SIZE HDD_SIZE [DISPLAY_TYPE] [OS_TYPE]"                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    exit 1                                                                                                                                                                                               # Colorize: green
fi                                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
if [ "${DISPLAY_TYPE}" == "" ]; then                                                                                                                                                                     # Colorize: green
    DISPLAY_TYPE=vnc                                                                                                                                                                                     # Colorize: green
fi                                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
if [ "${OS_TYPE}" == "" ]; then                                                                                                                                                                          # Colorize: green
    OS_TYPE=ngos                                                                                                                                                                                         # Colorize: green
fi                                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
#    PROCESSING                                                                                                                                                                                          # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
sudo virsh destroy  "${VM_NAME}"         2> /dev/null                                                                                                                                                    # Colorize: green
sudo virsh undefine "${VM_NAME}" --nvram 2> /dev/null                                                                                                                                                    # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
vboxmanage controlvm "${VM_NAME}" poweroff 2> /dev/null                                                                                                                                                  # Colorize: green
vboxmanage storageattach "${VM_NAME}" --storagectl "SATA Controller" --device 0 --port 0 --type hdd --medium none 2> /dev/null                                                                           # Colorize: green
vboxmanage unregistervm "${VM_NAME}" 2> /dev/null                                                                                                                                                        # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
sleep 3                                                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
cd ../                                                                                                                                                                                                   # Colorize: green
./make_hdd.sh ${HDD_SIZE} ${OS_TYPE} || exit 1                                                                                                                                                                       # Colorize: green
cd ${CURRENT_PATH}/                                                                                                                                                                                      # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
HDD_SIZE_IN_BYTES=$((${HDD_SIZE} * 1073741824))                                                                                                                                                          # Colorize: green
                                                                                                                                                                                                         # Colorize: green
mkdir -p ../../../build/disks/ 2> /dev/null                                                                                                                                                              # Colorize: green
rm "../../../build/disks/${VM_NAME}.vdi" 2> /dev/null                                                                                                                                                    # Colorize: green
cat "../../../build/disks/${VM_NAME}.img" | vboxmanage convertfromraw stdin "../../../build/disks/${VM_NAME}.vdi" ${HDD_SIZE_IN_BYTES} --uuid e7870c8a-2566-4906-8220-45d9de2f275c 2> /dev/null                    # Colorize: green
rm "../../../build/disks/${VM_NAME}.img"                                                                                                                                                                 # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
cp "template/${VM_NAME}/vm.vbox" "template/${VM_NAME}/${VM_NAME}.vbox"                                                                                                                                   # Colorize: green
sed -i "s/__PATH_TO_DISKS__/${CURRENT_PATH//\//\\/}\/..\/..\/..\/build\/disks\//g" "template/${VM_NAME}/${VM_NAME}.vbox"                                                                                 # Colorize: green
sed -i "s/__RAM_SIZE__/${RAM_SIZE}/g"                                              "template/${VM_NAME}/${VM_NAME}.vbox"                                                                                 # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
vboxmanage registervm "${CURRENT_PATH}/template/${VM_NAME}/${VM_NAME}.vbox"                                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
vboxmanage storagectl "${VM_NAME}" --name "SATA Controller" --add sata --controller IntelAHCI 2> /dev/null                                                                                               # Colorize: green
vboxmanage storageattach "${VM_NAME}" --storagectl "SATA Controller" --device 0 --port 0 --type hdd --medium "../../../build/disks/${VM_NAME}.vdi" 2> /dev/null                                          # Colorize: green
                                                                                                                                                                                                         # Colorize: green
vboxmanage startvm "${VM_NAME}"                                                                                                                                                                          # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo "NGOS VirtualBox VM started"                                                                                                                                                                        # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
NGOS_LOGGER_PID=`ps -ef | grep "tail -f -n +1 logs/" | grep -v grep | awk '{print $2}'`                                                                                                                  # Colorize: green
kill -9 ${NGOS_LOGGER_PID} > /dev/null 2>&1                                                                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
socat unix-connect:${TTY} pty,link=${TTY}-pty,raw,echo=0 &                                                                                                                               # Colorize: green
sleep 1                                                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
mkdir logs/ 2> /dev/null                                                                                                                                                                                 # Colorize: green
cat ${TTY}-pty > "logs/${VM_NAME}.log" &                                                                                                                                                         # Colorize: green
sleep 1                                                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
tail -f -n +1 "logs/${VM_NAME}.log" |                                                                                                                                                                    # Colorize: green
    while IFS= read -r line                                                                                                                                                                              # Colorize: green
    do                                                                                                                                                                                                   # Colorize: green
        echo "${line}"                                                                                                                                                                                   # Colorize: green
    done                                                                                                                                                                                                 # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
exit 0                                                                                                                                                                                                   # Colorize: green
