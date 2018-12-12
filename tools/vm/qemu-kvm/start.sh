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



sudo virsh destroy  "${VM_NAME}"         2> /dev/null
sudo virsh undefine "${VM_NAME}" --nvram 2> /dev/null



cd ../
./make_hdd.sh ${OS_TYPE} || exit 1
cd ${CURRENT_PATH}/



mkdir -p ../../../build/disks/ 2> /dev/null
sudo rm "../../../build/disks/${VM_NAME}.raw" 2> /dev/null
qemu-img convert -O raw "../../../build/disks/${VM_NAME}.img" "../../../build/disks/${VM_NAME}.raw" 2> /dev/null
rm "../../../build/disks/${VM_NAME}.img"



sudo virt-install --name ${VM_NAME} \
    --connect qemu:///system \
    --virt-type kvm \
    --arch=x86_64 \
    --os-variant=none \
    --ram ${RAM_SIZE} \
    --vcpus 2 \
    --cpu host-passthrough,cache.mode=passthrough \
    --graphics ${DISPLAY_TYPE} \
    --video=vmvga \
    --disk path="../../../build/disks/${VM_NAME}.raw",format=raw,bus=virtio,cache=none \
    --serial unix,path=/tmp/qemukvmttyS0 \
    --boot loader=/usr/share/edk2.git/ovmf-x64/OVMF_CODE-pure-efi.fd,loader_ro=yes,loader_type=pflash,nvram_template=/usr/share/edk2.git/ovmf-x64/OVMF_VARS-pure-efi.fd \
    --qemu-commandline="-gdb tcp::1234" \
    --noautoconsole



sudo virsh start "${VM_NAME}" 2> /dev/null

if [ "${DISPLAY_TYPE}" != "none" ]; then
    virt-viewer -c qemu:///system "${VM_NAME}" &
fi



echo "NGOS QEMU-KVM VM started"



NGOS_LOGGER_PID=`ps -ef | grep "tail -f -n +1 logs/" | grep -v grep | awk '{print $2}'`
kill -9 ${NGOS_LOGGER_PID} > /dev/null 2>&1



sudo socat unix-connect:/tmp/qemukvmttyS0 pty,link=/tmp/qemukvmttyS0-pty,raw,echo=0 &
sleep 1



mkdir logs/ 2> /dev/null
sudo cat /tmp/qemukvmttyS0-pty > "logs/${VM_NAME}.log" &
sleep 1

tail -f -n +1 "logs/${VM_NAME}.log" |
    while IFS= read -r line
    do
        echo "$line"
    done



exit 0
