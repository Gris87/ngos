#!/bin/bash

# This script helps to create RAW disk image that can be used by VM
# Author: Maxim Shvecov
# Usage: ./make_hdd.sh [OS_TYPE]



###########################################################################################
#    PARAMETERS
###########################################################################################



VM_NAME="NGOS_dev"
OS_TYPE=$1

SINGLE_IMAGE=1
BOOTLOADER_IMAGE=../../build/deployment/com.ngos.bootloader/*



if [ "${OS_TYPE}" == "" ]; then
    OS_TYPE=ngos
fi



if [ "${OS_TYPE}" == "ngos" ]; then
    KERNEL_IMAGE=../../build/deployment/com.ngos.kernel/kernel.efi
elif [ "${OS_TYPE}" == "ngos_installer" ]; then
    KERNEL_IMAGE=../../build/deployment/com.ngos.installer/installer.efi
elif [ "${OS_TYPE}" == "linux" ]; then
    KERNEL_IMAGE=../../../linux/arch/x86/boot/bzImage
elif [ "${OS_TYPE}" == "win7" ]; then
    SINGLE_IMAGE=0
    KERNEL_IMAGE=../tracers/assets/win7/*
elif [ "${OS_TYPE}" == "win10" ]; then
    SINGLE_IMAGE=0
    KERNEL_IMAGE=../tracers/assets/win10/*
else
    echo "Invalid OS_TYPE value: ${OS_TYPE}"
    exit 1
fi



###########################################################################################
#    PROCESSING
###########################################################################################



mkdir -p ../../build/disks/ 2> /dev/null



truncate --size 1G "../../build/disks/${VM_NAME}.img"
sgdisk --zap-all \
    --new 1::+100M --typecode=1:EF00 --change-name=1:"UEFI System" \
    --new 2::-0 --typecode=2:8300 --change-name=2:"NGOS filesystem" \
    "../../build/disks/${VM_NAME}.img"



LOOPDEV=`sudo losetup --find --show "../../build/disks/${VM_NAME}.img"`
sudo partprobe ${LOOPDEV}



sudo mkfs.fat -F32 -s2 -n "UEFI BOOT" ${LOOPDEV}p1



MOUNTDIR=$(mktemp -d -t demoXXXXXX)
sudo mount ${LOOPDEV}p1 ${MOUNTDIR}

if [ ${SINGLE_IMAGE} -eq 1 ]; then
    sudo mkdir -p ${MOUNTDIR}/EFI/BOOT/
    sudo mkdir -p ${MOUNTDIR}/EFI/NGOS/

    # TODO: Uncomment later
    # sudo cp -r ${BOOTLOADER_IMAGE} ${MOUNTDIR}/EFI/BOOT/
    # sudo cp ${KERNEL_IMAGE}        ${MOUNTDIR}/EFI/NGOS/
    sudo cp ../../build/deployment/com.ngos.bootloader/tools/cputest.efi ${MOUNTDIR}/EFI/BOOT/bootx64.efi
else
    sudo cp -r ${KERNEL_IMAGE} ${MOUNTDIR}/
fi

echo "Files on ESP:"
sudo find ${MOUNTDIR} | cut -d / -f 4-

sudo umount ${MOUNTDIR}



rm -rf ${MOUNTDIR}
sudo losetup -d ${LOOPDEV}



exit 0
