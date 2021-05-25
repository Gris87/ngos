#!/bin/bash
                                                                                                                                                                                                         # Colorize: green
# This script helps to add tag for new version                                                                                                                                                           # Colorize: green
# Author: Maxim Shvecov                                                                                                                                                                                  # Colorize: green
# Usage: ./scripts/add_version_tag.sh                                                                                                                                                                    # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
#    VERIFICATION                                                                                                                                                                                        # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
if [ ! -f ngos.files ]; then                                                                                                                                                                             # Colorize: green
    echo "Please run this script from the root folder"                                                                                                                                                   # Colorize: green
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
LAST_VERSION=`git tag | grep -E -e "[0-9]+_v[0-9.]+" | sort | tail -n 1 | sed -r "s/[0-9]+_v([0-9.]+.*)/\1/g"`                                                                                           # Colorize: green
                                                                                                                                                                                                         # Colorize: green
if [ "${LAST_VERSION}" == "" ]; then                                                                                                                                                                     # Colorize: green
    LAST_VERSION=0.0.0                                                                                                                                                                                   # Colorize: green
fi                                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
IS_RC=`echo "${LAST_VERSION}" | grep rc`                                                                                                                                                                 # Colorize: green
                                                                                                                                                                                                         # Colorize: green
if [ "${IS_RC}" != "" ]; then                                                                                                                                                                            # Colorize: green
    NEW_VERSION=`echo "${LAST_VERSION}" | sed -r "s/(.*)-rc.*/\1/g"`                                                                                                                                     # Colorize: green
else                                                                                                                                                                                                     # Colorize: green
    VERSION_PARTS=(`echo "${LAST_VERSION}" | tr "\." " "`)                                                                                                                                               # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    if [ ${VERSION_PARTS[2]} -ge 9 ]; then                                                                                                                                                               # Colorize: green
        VERSION_PARTS[2]=0                                                                                                                                                                               # Colorize: green
        VERSION_PARTS[1]=$((${VERSION_PARTS[1]} + 1))                                                                                                                                                    # Colorize: green
    else                                                                                                                                                                                                 # Colorize: green
        VERSION_PARTS[2]=$((${VERSION_PARTS[2]} + 1))                                                                                                                                                    # Colorize: green
    fi                                                                                                                                                                                                   # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    NEW_VERSION=${VERSION_PARTS[0]}.${VERSION_PARTS[1]}.${VERSION_PARTS[2]}                                                                                                                              # Colorize: green
fi                                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
NEW_TAG=`date +%Y%m%d`_v${NEW_VERSION}                                                                                                                                                                   # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
git tag -a ${NEW_TAG} -m "Version ${NEW_VERSION}"                                                                                                                                                        # Colorize: green
./scripts/commit.sh "Version ${NEW_VERSION}"                                                                                                                                                             # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
exit 0                                                                                                                                                                                                   # Colorize: green
