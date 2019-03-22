#!/bin/bash

# This script helps to start VM
# Author: Maxim Shvecov
# Usage: ./start.sh RAM_SIZE [DISPLAY_TYPE] [OS_TYPE]



###########################################################################################
#    PARAMETERS
###########################################################################################



CURRENT_PATH=`pwd`
VM_NAME="NGOS_dev"
RAM_SIZE=$1
DISPLAY_TYPE=$2
OS_TYPE=$3



###########################################################################################
#    VERIFICATION
###########################################################################################



if [ "${RAM_SIZE}" == "" ]; then
    echo "Please specify RAM size."
    echo "    Usage: ./start.sh RAM_SIZE [DISPLAY_TYPE] [OS_TYPE]"

    exit 1
fi



if [ "${DISPLAY_TYPE}" == "" ]; then
    DISPLAY_TYPE=vnc
fi



if [ "${OS_TYPE}" == "" ]; then
    OS_TYPE=ngos
fi



###########################################################################################
#    PROCESSING
###########################################################################################



cp "template/${VM_NAME}/vm.vbox" "template/${VM_NAME}/${VM_NAME}.vbox"
sed -i "s/__PATH_TO_DISKS__/${CURRENT_PATH//\//\\/}\/..\/..\/..\/build\/disks\//g" "template/${VM_NAME}/${VM_NAME}.vbox"
sed -i "s/__RAM_SIZE__/${RAM_SIZE}/g"                                              "template/${VM_NAME}/${VM_NAME}.vbox"



vboxmanage controlvm "${VM_NAME}" poweroff 2> /dev/null
vboxmanage storageattach "${VM_NAME}" --storagectl "SATA Controller" --device 0 --port 0 --type hdd --medium none 2> /dev/null
vboxmanage unregistervm "${VM_NAME}" 2> /dev/null



cd ../
./make_hdd.sh ${OS_TYPE} || exit 1
cd ${CURRENT_PATH}/



mkdir -p ../../../build/disks/ 2> /dev/null
rm "../../../build/disks/${VM_NAME}.vdi" 2> /dev/null
cat "../../../build/disks/${VM_NAME}.img" | vboxmanage convertfromraw stdin "../../../build/disks/${VM_NAME}.vdi" 1073741824 --uuid e7870c8a-2566-4906-8220-45d9de2f275c 2> /dev/null
rm "../../../build/disks/${VM_NAME}.img"



vboxmanage registervm "${CURRENT_PATH}/template/${VM_NAME}/${VM_NAME}.vbox"

vboxmanage storagectl "${VM_NAME}" --name "SATA Controller" --add sata --controller IntelAHCI 2> /dev/null
vboxmanage storageattach "${VM_NAME}" --storagectl "SATA Controller" --device 0 --port 0 --type hdd --medium "../../../build/disks/${VM_NAME}.vdi" 2> /dev/null

vboxmanage startvm "${VM_NAME}"

echo "NGOS VirtualBox VM started"



NGOS_LOGGER_PID=`ps -ef | grep "tail -f -n +1 logs/" | grep -v grep | awk '{print $2}'`
kill -9 ${NGOS_LOGGER_PID} > /dev/null 2>&1



socat unix-connect:/tmp/vboxttyS0 pty,link=/tmp/vboxttyS0-pty,raw,echo=0 &
sleep 1



mkdir logs/ 2> /dev/null
cat /tmp/vboxttyS0-pty > "logs/${VM_NAME}.log" &
sleep 1

tail -f -n +1 "logs/${VM_NAME}.log" |
    while IFS= read -r line
    do
        echo "${line}"
    done



exit 0
