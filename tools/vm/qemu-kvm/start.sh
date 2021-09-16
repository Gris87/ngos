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
PATH_TO_DISKS=${CURRENT_PATH}/../../../build/disks                                                                                                                                                          # Colorize: green
TTY=`mktemp -t ngos_ttyS0_qemu_kvm_XXXX`                                                                                                                                                                     # Colorize: green
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
sudo rm "${PATH_TO_DISKS}/${VM_NAME}.raw" 2> /dev/null                                                                                                                                               # Colorize: green
qemu-img convert -O raw "${PATH_TO_DISKS}/${VM_NAME}.img" "${PATH_TO_DISKS}/${VM_NAME}.raw" 2> /dev/null                                                                                         # Colorize: green
rm "${PATH_TO_DISKS}/${VM_NAME}.img"                                                                                                                                                                 # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
ARCH=`grep "define NGOS_BUILD_ARCH" ../../../include/buildconfig.h | sed -r "s/.*OPTION_ARCH_([a-zA-Z0-9_]+).*/\1/g" | tr "[:upper:]" "[:lower:]"`                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
sudo virt-install --name ${VM_NAME}                                                 \
    --connect qemu:///system                                                        \
    --virt-type kvm                                                                 \
    --arch=${ARCH}                                                                  \
    --os-variant=none                                                               \
    --ram ${RAM_SIZE}                                                               \
    --vcpus 4,sockets=1,cores=2,threads=2                                           \
    --cpu host                                                                      \
    --graphics ${DISPLAY_TYPE}                                                      \
    --video=vga                                                                     \
    --network network=default,model=virtio                                          \
    --disk path="${PATH_TO_DISKS}/${VM_NAME}.raw",format=raw,bus=virtio,cache=none  \
    --serial unix,path=${TTY}                                                       \
    --boot uefi                                                                     \
    --qemu-commandline="-gdb tcp::1234"                                             \
    --noautoconsole                                                                                                                                                                                      # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
sudo virsh start "${VM_NAME}" 2> /dev/null                                                                                                                                                               # Colorize: green
                                                                                                                                                                                                         # Colorize: green
if [ "${DISPLAY_TYPE}" != "none" ]; then                                                                                                                                                                 # Colorize: green
    virt-viewer -c qemu:///system "${VM_NAME}" &                                                                                                                                                         # Colorize: green
fi                                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo "NGOS QEMU-KVM VM started"                                                                                                                                                                          # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
NGOS_LOGGER_PID=`ps -ef | grep "tail -f -n +1 logs/" | grep -v grep | awk '{print $2}'`                                                                                                                  # Colorize: green
kill -9 ${NGOS_LOGGER_PID} > /dev/null 2>&1                                                                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
sudo socat unix-connect:${TTY} pty,link=${TTY}-pty,raw,echo=0 &                                                                                                                    # Colorize: green
sleep 1                                                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
mkdir logs/ 2> /dev/null                                                                                                                                                                                 # Colorize: green
sudo cat ${TTY}-pty > "logs/${VM_NAME}.log" &                                                                                                                                                 # Colorize: green
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
