#!/bin/bash                                                                                                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
# This script helps to start VM with a specified VIRTUAL_MANAGER                                                                                                                                         # Colorize: green
# Author: Maxim Shvecov                                                                                                                                                                                  # Colorize: green
# Usage: ./start_vm.sh VIRTUAL_MANAGER [DISPLAY_TYPE] [OS_TYPE]                                                                                                                                          # Colorize: green
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
VIRTUAL_MANAGER=$1                                                                                                                                                                                       # Colorize: green
DISPLAY_TYPE=$2                                                                                                                                                                                          # Colorize: green
OS_TYPE=$3                                                                                                                                                                                               # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
#    VERIFICATION                                                                                                                                                                                        # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
if [ "${VIRTUAL_MANAGER}" == "" ]; then                                                                                                                                                                  # Colorize: green
    echo "Please specify virtual manager."                                                                                                                                                               # Colorize: green
    echo "    Usage: ./start_vm.sh VIRTUAL_MANAGER [DISPLAY_TYPE] [OS_TYPE]"                                                                                                                             # Colorize: green
                                                                                                                                                                                                         # Colorize: green
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
cd ${VIRTUAL_MANAGER}/                                                                                                                                                                                   # Colorize: green
./start.sh 1024 ${DISPLAY_TYPE} ${OS_TYPE}                                                                                                                                                               # Colorize: green
cd ${CURRENT_PATH}/                                                                                                                                                                                      # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
exit 0                                                                                                                                                                                                   # Colorize: green
