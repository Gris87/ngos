#!/bin/bash

# This script helps to generate keys required for Secure Boot
# Author: Maxim Shvecov
# Usage: ./scripts/generate_secure_boot_keys.sh



###########################################################################################
#    PARAMETERS
###########################################################################################



CURRENT_PATH=`pwd`



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



cd secure_boot/



openssl req -new -x509 -newkey rsa:2048 -sha256 -days 36500 -subj "/CN=Platform Key"      -keyout PK.key  -out PK.pem  -nodes
openssl req -new -x509 -newkey rsa:2048 -sha256 -days 36500 -subj "/CN=Key Exchange Key"  -keyout KEK.key -out KEK.pem -nodes
openssl req -new -x509 -newkey rsa:2048 -sha256 -days 36500 -subj "/CN=Image Signing Key" -keyout ISK.key -out ISK.pem -nodes

cert-to-efi-sig-list -g "`uuidgen`" PK.pem  PK.esl
cert-to-efi-sig-list -g "`uuidgen`" KEK.pem KEK.esl
cert-to-efi-sig-list -g "`uuidgen`" ISK.pem ISK.esl



wget http://go.microsoft.com/fwlink/?LinkID=321192 -O MicWinProPCA2011_2011-10-19.crt
wget http://go.microsoft.com/fwlink/?LinkId=321194 -O MicCorUEFCA2011_2011-06-27.crt



openssl x509 -in MicWinProPCA2011_2011-10-19.crt -inform DER -out MsWin.pem -outform PEM
openssl x509 -in MicCorUEFCA2011_2011-06-27.crt  -inform DER -out UEFI.pem  -outform PEM

rm MicWinProPCA2011_2011-10-19.crt MicCorUEFCA2011_2011-06-27.crt

cert-to-efi-sig-list -g "`uuidgen`" MsWin.pem MsWin.esl
cert-to-efi-sig-list -g "`uuidgen`" UEFI.pem  UEFI.esl

rm MsWin.pem UEFI.pem

cat ISK.esl MsWin.esl UEFI.esl > db.esl
rm  ISK.esl MsWin.esl UEFI.esl



sign-efi-sig-list -k PK.key  -c PK.pem  PK  PK.esl  PK.auth
sign-efi-sig-list -k PK.key  -c PK.pem  KEK KEK.esl KEK.auth
sign-efi-sig-list -k KEK.key -c KEK.pem db  db.esl  db.auth

rm PK.key KEK.key
rm PK.pem KEK.pem
rm PK.esl KEK.esl db.esl



rm -rf setup/ 2> /dev/null
mkdir setup

mv PK.auth  setup/
mv KEK.auth setup/
mv db.auth  setup/



rm -rf keys/ 2> /dev/null
mkdir keys

mv ISK.key keys/
mv ISK.pem keys/

gpg -c -o keys/ISK.key.gpg keys/ISK.key



cd ${CURRENT_PATH}



exit 0
