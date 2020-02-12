#!/bin/bash

# This script helps to add tag for new version
# Author: Maxim Shvecov
# Usage: ./scripts/add_version_tag.sh



###########################################################################################
#    VERIFICATION
###########################################################################################



if [ ! -f ngos.files ]; then
    echo "Please run this script from the root folder"

    exit 1
fi



###########################################################################################
#    PROCESSING
###########################################################################################



LAST_VERSION=`git tag | grep -E -e "[0-9]+_v[0-9]+\.[0-9]+\.[0-9]+" | sort | tail -n 1 | cut -d _ -f 2 | cut -c 2-`



IS_RC=`echo "${LAST_VERSION}" | grep rc`

if [ "${IS_RC}" != "" ]; then
    NEW_VERSION=`echo "${LAST_VERSION}" | cut -d "-" -f 1`
else
    VERSION_PARTS=(`echo "${LAST_VERSION}" | tr "\." " "`)



    if [ ${VERSION_PARTS[2]} -ge 9 ]; then
        VERSION_PARTS[2]=0
        VERSION_PARTS[1]=$((${VERSION_PARTS[1]} + 1))
    else
        VERSION_PARTS[2]=$((${VERSION_PARTS[2]} + 1))
    fi



    NEW_VERSION=${VERSION_PARTS[0]}.${VERSION_PARTS[1]}.${VERSION_PARTS[2]}
fi



NEW_TAG=`date +%Y%m%d`_v${NEW_VERSION}



git tag -a ${NEW_TAG} -m "Version ${NEW_VERSION}"
./scripts/commit.sh "Version ${NEW_VERSION}"



exit 0
