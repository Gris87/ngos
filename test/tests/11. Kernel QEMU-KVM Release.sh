#!/bin/bash
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
#    PARAMETERS                                                                                                                                                                                          # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
WORKING_DIR=`pwd`                                                                                                                                                                                        # Colorize: green
BUILD_CONFIG=include/buildconfig.h                                                                                                                                                                       # Colorize: green
BUILD_LOG=/tmp/ngos_test.log                                                                                                                                                                             # Colorize: green
BUILD_CFG_BACKUP=/tmp/ngos_test_buildconfig2.h                                                                                                                                                           # Colorize: green
TEMP_LOG=/tmp/ngos_kernel.log                                                                                                                                                                            # Colorize: green
LOG_PATH=../../tools/vm/qemu-kvm/logs/NGOS_dev.log                                                                                                                                                       # Colorize: green
VM_NAME="NGOS_dev"                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
#    PROCESSING                                                                                                                                                                                          # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo -e "\e[36m==================================================\e[0m"                                                                                                                                  # Colorize: green
echo -e "\e[36m                   Test: Kernel\e[0m"                                                                                                                                                     # Colorize: green
echo -e "\e[36m==================================================\e[0m"                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
echo -e "\e[33m-------------------- Building --------------------\e[0m"                                                                                                                                  # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
cd ../../                                                                                                                                                                                                # Colorize: green
cp ${BUILD_CONFIG} ${BUILD_CFG_BACKUP}                                                                                                                                                                   # Colorize: green
                                                                                                                                                                                                         # Colorize: green
tools/qt/build_config_maker/build/build_config_maker ${BUILD_CONFIG} NGOS_BUILD_X86_64_VECTORIZATION_MODE=OPTION_X86_64_VECTORIZATION_MODE_AVX2 NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD=OPTION_X86_64_FUSED_MULTIPLY_ADD_FMA3 > ${BUILD_LOG} 2>&1 # Colorize: green
make test-release >> ${BUILD_LOG} 2>&1                                                                                                                                                                   # Colorize: green
                                                                                                                                                                                                         # Colorize: green
if [ $? -ne 0 ]; then                                                                                                                                                                                    # Colorize: green
    cat ${BUILD_LOG} 2>&1                                                                                                                                                                                # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    cp ${BUILD_CFG_BACKUP} ${BUILD_CONFIG}                                                                                                                                                               # Colorize: green
    cd ${WORKING_DIR}/                                                                                                                                                                                   # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    exit 1                                                                                                                                                                                               # Colorize: green
fi                                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
cp ${BUILD_CFG_BACKUP} ${BUILD_CONFIG}                                                                                                                                                                   # Colorize: green
cd ${WORKING_DIR}/                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
echo -e "\e[33m------------------ Starting QEMU -----------------\e[0m"                                                                                                                                  # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
cd ../../tools/vm                                                                                                                                                                                        # Colorize: green
./start_vm.sh qemu-kvm none > ${TEMP_LOG} 2>&1 &                                                                                                                                                         # Colorize: green
cd ${WORKING_DIR}/                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
sleep 30                                                                                                                                                                                                 # Colorize: green
cat ${TEMP_LOG}                                                                                                                                                                                          # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
echo -e "\e[33m------------------ Killing QEMU ------------------\e[0m"                                                                                                                                  # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
sudo virsh destroy  "${VM_NAME}"         2> /dev/null                                                                                                                                                    # Colorize: green
sudo virsh undefine "${VM_NAME}" --nvram 2> /dev/null                                                                                                                                                    # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
echo -e "\e[33m----------------- Checking output ----------------\e[0m"                                                                                                                                  # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
ERRORS=` \
    grep \
        -E \
        -e "ASSERT" \
        -e "ERROR" \
        -e "CRITICAL" \
        -e "FATAL" \
        -e "Testing completed: [0-9]+ passed, ([0-9]{2,}|[1-9]) failed" \
    ${LOG_PATH}                                                                                                                                                                                          # Colorize: green
`                                                                                                                                                                                                        # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
if [ "${ERRORS}" != "" ]; then                                                                                                                                                                           # Colorize: green
    echo "Errors:"                                                                                                                                                                                       # Colorize: green
    echo "${ERRORS}"                                                                                                                                                                                     # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    exit 1                                                                                                                                                                                               # Colorize: green
fi                                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo "OK"                                                                                                                                                                                                # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
exit 0                                                                                                                                                                                                   # Colorize: green
