#!/bin/bash



###########################################################################################
#    PARAMETERS
###########################################################################################



WORKING_DIR=`pwd`
BUILD_CONFIG=include/buildconfig.h
BUILD_LOG=/tmp/ngos_test.log
BUILD_CFG_BACKUP=/tmp/ngos_test_buildconfig2.h
TEMP_LOG=/tmp/ngos_kernel.log
LOG_PATH=../../tools/vm/qemu/logs/NGOS_dev.log
VM_NAME="NGOS_dev"



###########################################################################################
#    PROCESSING
###########################################################################################



echo -e "\e[36m==================================================\e[0m"
echo -e "\e[36m                   Test: Kernel\e[0m"
echo -e "\e[36m==================================================\e[0m"



echo ""
echo -e "\e[33m-------------------- Building --------------------\e[0m"
echo ""



cd ../../
cp ${BUILD_CONFIG} ${BUILD_CFG_BACKUP}

tools/qt/build_config_maker/build/build_config_maker ${BUILD_CONFIG} NGOS_BUILD_X86_64_VECTORIZATION_MODE=OPTION_X86_64_VECTORIZATION_MODE_SSE2 NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD=OPTION_X86_64_FUSED_MULTIPLY_ADD_NONE > ${BUILD_LOG} 2>&1
make test-release >> ${BUILD_LOG} 2>&1

if [ $? -ne 0 ]; then
    cat ${BUILD_LOG} 2>&1

    cp ${BUILD_CFG_BACKUP} ${BUILD_CONFIG}
    cd ${WORKING_DIR}/

    exit 1
fi

cp ${BUILD_CFG_BACKUP} ${BUILD_CONFIG}
cd ${WORKING_DIR}/



echo ""
echo -e "\e[33m------------------ Starting QEMU -----------------\e[0m"
echo ""



cd ../../tools/vm
./start_vm.sh qemu none > ${TEMP_LOG} 2>&1 &
cd ${WORKING_DIR}/



sleep 30
cat ${TEMP_LOG}



echo ""
echo -e "\e[33m------------------ Killing QEMU ------------------\e[0m"
echo ""



sudo virsh destroy  "${VM_NAME}"         2> /dev/null
sudo virsh undefine "${VM_NAME}" --nvram 2> /dev/null



echo ""
echo -e "\e[33m----------------- Checking output ----------------\e[0m"
echo ""



ERRORS=` \
    grep \
        -E \
        -e "ASSERT" \
        -e "ERROR" \
        -e "CRITICAL" \
        -e "FATAL" \
        -e "Testing completed: [0-9]+ passed, ([0-9]{2,}|[1-9]) failed" \
    ${LOG_PATH}
`



if [ "${ERRORS}" != "" ]; then
    echo "Errors:"
    echo "${ERRORS}"

    exit 1
fi

echo "OK"



exit 0
