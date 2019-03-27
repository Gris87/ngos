#!/bin/bash

# This script helps to perform all the required setup for the server
# Author: Maxim Shvecov
# Usage: sudo ./setup.sh



###########################################################################################
#    PARAMETERS
###########################################################################################



SILENT_MODE=$1



if [ "${SILENT_MODE}" == "" ]; then
    SILENT_MODE=0
else
    SILENT_MODE=1
fi



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

    echo "NGOS webapp installed"

    return 0
}



function setup_server_name
{
    SERVER_NAME_VALUE=`mysql -u root -D ngos -NB -e "SELECT value FROM properties WHERE name='server_name';"`

    if [ "${SERVER_NAME_VALUE}" == "" ]; then
        SERVER_NAME=$1

        while [ "${SERVER_NAME}" == "" ];
        do
            echo -n "Enter server name: "
            read SERVER_NAME
        done

        mysql -u root -D ngos -e "INSERT INTO properties (name, value) VALUES ('server_name', '${SERVER_NAME}');" || return 1
    else
        if [ ${SILENT_MODE} -eq 0 ]; then
            while true
            do
                echo "This operation is only required in case when your server DNS name changed."
                echo "It is your responsibility to update server list information on all other servers."
                echo -n "Do you really need to change server name? (Y/n) "
                read CONFIRM

                if [ "${CONFIRM}" == "" -o "${CONFIRM}" == "y" -o "${CONFIRM}" == "Y" ]; then
                    CONFIRM=1
                    break
                elif [ "${CONFIRM}" == "n" -o "${CONFIRM}" == "N" ]; then
                    CONFIRM=0
                    break
                fi
            done
        else
            CONFIRM=1
        fi

        if [ ${CONFIRM} -eq 1 ]; then
            SERVER_NAME=$1

            while [ "${SERVER_NAME}" == "" ];
            do
                echo -n "Enter server name: "
                read SERVER_NAME
            done

            if [ "${SERVER_NAME}" != "${SERVER_NAME_VALUE}" ]; then
                mysql -u root -D ngos -e "UPDATE properties SET value='${SERVER_NAME}' WHERE name='server_name';" || return 1
            fi
        else
            return 1
        fi
    fi



    return 0
}



function generate_secret_key
{
    SECRET_KEY=`cat /dev/urandom | tr -dc "a-zA-Z0-9" | fold -w 1000 | head -n 1`



    SECRET_KEY_ID=`mysql -u root -D ngos -NB -e "SELECT id FROM properties WHERE name='secret_key';"`

    if [ "${SECRET_KEY_ID}" == "" ]; then
        mysql -u root -D ngos -e "INSERT INTO properties (name, value) VALUES ('secret_key', '${SECRET_KEY}');" || return 1
    else
        mysql -u root -D ngos -e "UPDATE properties SET value='${SECRET_KEY}' WHERE id=${SECRET_KEY_ID};" || return 1
    fi



    echo "Secret key:"
    echo "${SECRET_KEY}"



    return 0
}



function update_sources
{
    cp -r html/. /var/www/html || return 1

    echo "NGOS webapp sources updated"

    return 0
}



function register_server
{
    echo "TBD"

    return 0
}



function validate_setup
{
    echo "TBD"

    return 0
}



function print_server_name
{
    echo "TBD"

    return 0
}



function print_secret_key
{
    echo "TBD"

    return 0
}



function uninstall_sources
{
    if [ -d /var/www/html ]; then
        rm -rf /var/www/html || return 1

        echo "NGOS webapp uninstalled"
    else
        echo "Directory \"/var/www/html\" not found"

        return 1
    fi



    return 0
}



function drop_database
{
    mysql -u root -e "DROP DATABASE ngos" || return 1

    echo "NGOS database dropped"

    return 0
}



function quit()
{
    QUIT=1

    return 0
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

    return 0
}



function step2_options()
{
    TITLE="Common stuff"

    TEXT[0]="Update webapp sources"
    FUNC[0]="update_sources"

    TEXT[1]="Register new server"
    FUNC[1]="register_server"

    return 0
}



function step3_options()
{
    TITLE="Verification"

    TEXT[0]="Validate setup"
    FUNC[0]="validate_setup"

    TEXT[1]="Print server name"
    FUNC[1]="print_server_name"

    TEXT[2]="Print secret key"
    FUNC[2]="print_secret_key"

    return 0
}



function step4_options()
{
    TITLE="Uninstall"

    TEXT[0]="Uninstall webapp sources"
    FUNC[0]="uninstall_sources"

    TEXT[1]="Drop database"
    FUNC[1]="drop_database"

    return 0
}



function display_menu
{
    STEPS=( step1_options step2_options step3_options step4_options )
    STEPS_COUNT=${#STEPS[@]}



    QUIT=0

    while [ ${QUIT} -eq 0 ];
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

        echo "[0] Exit"
        OPTIONS[0]="quit"



        echo ""
        echo -n "Option: "
        read SELECTED_OPTION



        echo ""
        ${OPTIONS[${SELECTED_OPTION}]}
        EXIT_CODE=$?



        if [ ${QUIT} -eq 0 ]; then
            echo ""

            if [ ${EXIT_CODE} -eq 0 ]; then
                echo "Success"
            else
                echo "Failed"
            fi



            echo ""
            echo -n "Press enter to continue ..."
            read
        fi
    done



    return 0
}



###########################################################################################
#    PROCESSING
###########################################################################################



display_menu || exit 1



exit 0
