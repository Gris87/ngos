#!/bin/bash

# This script helps to perform all the required setup for the server
# Author: Maxim Shvecov
# Usage: sudo ./setup.sh



###########################################################################################
#    VERIFICATION
###########################################################################################



if [ ${EUID} -ne 0 ]; then
    echo "Please run as root"

    exit 1
fi



###########################################################################################
#    FUNCTIONS
###########################################################################################



function install_sources
{
    ./install.sh || return 1

    return 0;
}



function setup_server_name
{
    echo "TBD"

    return 1;
}



function generate_secret_key
{
    SECRET_KEY=`cat /dev/urandom | tr -dc "a-zA-Z0-9" | fold -w 1000 | head -n 1`



    SECRET_KEY_ID=`mysql -u root -D ngos -NB -e "SELECT id FROM properties WHERE name='secret_key';"`

    if [ "${SECRET_KEY_ID}" == "" ]; then
        mysql -u root -D ngos -e "INSERT INTO properties (name, value) VALUES ('secret_key', '${SECRET_KEY}');"
    else
        mysql -u root -D ngos -e "UPDATE properties SET value='${SECRET_KEY}' WHERE id=${SECRET_KEY_ID};"
    fi



    echo "Secret key:"
    echo "${SECRET_KEY}"



    return 0;
}



function update_sources
{
    cp -r html/. /var/www/html || return 1

    return 0;
}



function register_server
{
    echo "TBD"

    return 0;
}



function validate_setup
{
    echo "TBD"

    return 0;
}



function uninstall_sources
{
    rm -rf /var/www/html || return 1

    return 0;
}



function drop_database
{
    echo "TBD"

    return 0;
}



function quit()
{
    QUIT=1

    return 0;
}



function step1_options()
{
    TITLE="Initial setup"

    TEXT[0]="Install webapp sources on the server"
    FUNC[0]="install_sources"

    TEXT[1]="Setup server name"
    FUNC[1]="setup_server_name"

    TEXT[2]="Generate server secret key"
    FUNC[2]="generate_secret_key"

    return 0;
}



function step2_options()
{
    TITLE="Common stuff"

    TEXT[0]="Update webapp sources"
    FUNC[0]="update_sources"

    TEXT[1]="Register new server"
    FUNC[1]="register_server"

    return 0;
}



function step3_options()
{
    TITLE="Verification"

    TEXT[0]="Validate setup"
    FUNC[0]="validate_setup"

    return 0;
}



function step4_options()
{
    TITLE="Uninstall"

    TEXT[0]="Uninstall webapp sources"
    FUNC[0]="uninstall_sources"

    TEXT[1]="Drop database"
    FUNC[1]="drop_database"

    return 0;
}



function display_menu
{
    STEPS=( step1_options step2_options step3_options step4_options )
    STEPS_COUNT=${#STEPS[@]}



    QUIT=0

    while [ "${QUIT}" == "0" ];
    do
        clear



        OPTION_NUM=1

        for ((s = 0; s < ${STEPS_COUNT}; s++))
        do
            ${STEPS[s]} || return 1



            echo "-----------------------------------------"
            echo " Step $s: ${TITLE}"
            echo "-----------------------------------------"

            OPTIONS_COUNT=${#TEXT[@]}

            for ((i = 0; i < ${OPTIONS_COUNT}; i++))
            do
                echo "[${OPTION_NUM}] ${TEXT[i]}"
                OPTIONS[${OPTION_NUM}]=${FUNC[i]}
                OPTION_NUM=$((${OPTION_NUM} + 1))
            done

            echo ""



            unset TEXT
            unset FUNC
        done

        echo "[${OPTION_NUM}] Exit"
        OPTIONS[${OPTION_NUM}]="quit"



        echo ""
        echo -n "Option: "
        read SELECTED_OPTION



        echo ""
        ${OPTIONS[${SELECTED_OPTION}]}



        if [ "$?" == "0" ]; then
            echo "Success"
        else
            echo "Failed"
        fi



        if [ "${QUIT}" == "0" ]; then
            echo ""
            echo -n "Press enter to continue ..."
            read
        fi
    done



    return 0;
}



###########################################################################################
#    PROCESSING
###########################################################################################



display_menu || exit 1



exit 0
