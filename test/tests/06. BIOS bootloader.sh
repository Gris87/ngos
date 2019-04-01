#!/bin/bash



###########################################################################################
#    PARAMETERS
###########################################################################################



QEMU_SCREENSHOT=/tmp/ngos_qemu_screen.ppm
DIFF_IMAGE=/tmp/ngos_qemu_screen_difference.png
EXPECTED_SCREENSHOT=assets/BIOS_screen.png



###########################################################################################
#    PROCESSING
###########################################################################################



echo -e "\e[36m==================================================\e[0m"
echo -e "\e[36m               Test: BIOS bootloader\e[0m"
echo -e "\e[36m==================================================\e[0m"



echo ""
echo -e "\e[33m------------------ Starting QEMU -----------------\e[0m"
echo ""



( sleep 3 ; echo "screendump ${QEMU_SCREENSHOT}" ; echo "quit" ) | \
    qemu-system-x86_64 -display none -drive file=../../build/deployment/com.ngos.kernel/NGOS_kernel.bin,format=raw -monitor stdio > /dev/null 2>&1

if [ $? -ne 0 ]; then
    exit 1
fi

convert ${QEMU_SCREENSHOT} -crop 1024x768+0+100 ${QEMU_SCREENSHOT}.png

echo "Screenshot taken: ${QEMU_SCREENSHOT}.png"



echo ""
echo -e "\e[33m----------------- Checking result ----------------\e[0m"
echo ""



echo "Comparing 2 screenshots ${QEMU_SCREENSHOT}.png and ${EXPECTED_SCREENSHOT}"
echo ""



COMPARE_RESULT=`compare -verbose -metric mae ${QEMU_SCREENSHOT}.png ${EXPECTED_SCREENSHOT} ${DIFF_IMAGE} 2>&1`
EXPECTED_OUTPUT=`echo "${COMPARE_RESULT}" | grep "all: 0 (0)"`

if [ "${EXPECTED_OUTPUT}" == "" ]; then
    echo "Screenshots are different"
    echo "${COMPARE_RESULT}"

    exit 1
fi

echo "OK"



exit 0
