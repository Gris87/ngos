#!/bin/bash                                                                                                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
# This script helps to create RAW disk image that can be used by VM                                                                                                                                      # Colorize: green
# Author: Maxim Shvecov                                                                                                                                                                                  # Colorize: green
# Usage: ./make_hdd.sh [OS_TYPE]                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
#    PARAMETERS                                                                                                                                                                                          # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
VM_NAME="NGOS_dev"                                                                                                                                                                                       # Colorize: green
OS_TYPE=$1                                                                                                                                                                                               # Colorize: green
                                                                                                                                                                                                         # Colorize: green
SINGLE_IMAGE=1                                                                                                                                                                                           # Colorize: green
BOOTLOADER_IMAGE=../../build/deployment/com.ngos.bootloader/*                                                                                                                                            # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
if [ "${OS_TYPE}" == "" ]; then                                                                                                                                                                          # Colorize: green
    OS_TYPE=ngos                                                                                                                                                                                         # Colorize: green
fi                                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
if [ "${OS_TYPE}" == "ngos" ]; then                                                                                                                                                                      # Colorize: green
    KERNEL_IMAGE=../../build/deployment/com.ngos.kernel/kernel.efi                                                                                                                                       # Colorize: green
elif [ "${OS_TYPE}" == "ngos_installer" ]; then                                                                                                                                                          # Colorize: green
    KERNEL_IMAGE=../../build/deployment/com.ngos.installer/installer.efi                                                                                                                                 # Colorize: green
elif [ "${OS_TYPE}" == "linux" ]; then                                                                                                                                                                   # Colorize: green
    KERNEL_IMAGE=../../../linux/arch/x86/boot/bzImage                                                                                                                                                    # Colorize: green
elif [ "${OS_TYPE}" == "win7" ]; then                                                                                                                                                                    # Colorize: green
    SINGLE_IMAGE=0                                                                                                                                                                                       # Colorize: green
    KERNEL_IMAGE=../tracers/assets/win7/*                                                                                                                                                                # Colorize: green
elif [ "${OS_TYPE}" == "win10" ]; then                                                                                                                                                                   # Colorize: green
    SINGLE_IMAGE=0                                                                                                                                                                                       # Colorize: green
    KERNEL_IMAGE=../tracers/assets/win10/*                                                                                                                                                               # Colorize: green
else                                                                                                                                                                                                     # Colorize: green
    echo "Invalid OS_TYPE value: ${OS_TYPE}"                                                                                                                                                             # Colorize: green
    exit 1                                                                                                                                                                                               # Colorize: green
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
mkdir -p ../../build/disks/ 2> /dev/null                                                                                                                                                                 # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
truncate --size 1G "../../build/disks/${VM_NAME}.img"                                                                                                                                                    # Colorize: green
sgdisk --zap-all \                                                                                                                                                                                       # Colorize: green
    --new 1::+100M --typecode=1:EF00 --change-name=1:"UEFI System" \                                                                                                                                     # Colorize: green
    --new 2::-0 --typecode=2:8300 --change-name=2:"NGOS filesystem" \                                                                                                                                    # Colorize: green
    "../../build/disks/${VM_NAME}.img"                                                                                                                                                                   # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
LOOPDEV=`sudo losetup --find --show "../../build/disks/${VM_NAME}.img"`                                                                                                                                  # Colorize: green
sudo partprobe ${LOOPDEV}                                                                                                                                                                                # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
sudo mkfs.fat -F32 -s2 -n "UEFI BOOT" ${LOOPDEV}p1                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
MOUNTDIR=$(mktemp -d -t demoXXXXXX)                                                                                                                                                                      # Colorize: green
sudo mount ${LOOPDEV}p1 ${MOUNTDIR}                                                                                                                                                                      # Colorize: green
                                                                                                                                                                                                         # Colorize: green
if [ ${SINGLE_IMAGE} -eq 1 ]; then                                                                                                                                                                       # Colorize: green
    sudo mkdir -p ${MOUNTDIR}/EFI/BOOT/                                                                                                                                                                  # Colorize: green
    sudo mkdir -p ${MOUNTDIR}/EFI/NGOS/                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    # TODO: Uncomment later                                                                                                                                                                              # Colorize: green
    # sudo cp -r ${BOOTLOADER_IMAGE} ${MOUNTDIR}/EFI/BOOT/                                                                                                                                               # Colorize: green
    # sudo cp ${KERNEL_IMAGE}        ${MOUNTDIR}/EFI/NGOS/                                                                                                                                               # Colorize: green
    sudo cp ../../build/deployment/com.ngos.bootloader/tools/networktest.efi ${MOUNTDIR}/EFI/BOOT/bootx64.efi                                                                                            # Colorize: green
else                                                                                                                                                                                                     # Colorize: green
    sudo cp -r ${KERNEL_IMAGE} ${MOUNTDIR}/                                                                                                                                                              # Colorize: green
fi                                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo "Files on ESP:"                                                                                                                                                                                     # Colorize: green
sudo find ${MOUNTDIR} | cut -d / -f 4-                                                                                                                                                                   # Colorize: green
                                                                                                                                                                                                         # Colorize: green
sudo umount ${MOUNTDIR}                                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
rm -rf ${MOUNTDIR}                                                                                                                                                                                       # Colorize: green
sudo losetup -d ${LOOPDEV}                                                                                                                                                                               # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
exit 0                                                                                                                                                                                                   # Colorize: green
