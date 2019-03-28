#!/bin/bash

# This script helps to perform all the required setup for the server
# Author: Maxim Shvecov
# Usage: sudo ./setup.sh



###########################################################################################
#    PARAMETERS
###########################################################################################



SILENT_MODE=$1
STEPS=( step1_options step2_options step3_options step4_options )
STEPS_COUNT=${#STEPS[@]}



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
                echo -n "Do you really need to change server name? (y/N) "
                read CONFIRM

                if [ "${CONFIRM}" == "y" -o "${CONFIRM}" == "Y" ]; then
                    CONFIRM=1
                    break
                elif [ "${CONFIRM}" == "" -o "${CONFIRM}" == "n" -o "${CONFIRM}" == "N" ]; then
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
            echo "Canceled"

            return 1
        fi
    fi



    echo "Server name changed to ${SERVER_NAME}"

    return 0
}



function generate_secret_key
{
    SECRET_KEY=`cat /dev/urandom | tr -dc "a-zA-Z0-9" | fold -w 1000 | head -n 1`



    SECRET_KEY_ID=`mysql -u root -D ngos -NB -e "SELECT id FROM properties WHERE name='secret_key';"`

    if [ "${SECRET_KEY_ID}" == "" ]; then
        mysql -u root -D ngos -e "INSERT INTO properties (name, value) VALUES ('secret_key', '${SECRET_KEY}');" || return 1
    else
        if [ ${SILENT_MODE} -eq 0 ]; then
            while true
            do
                echo "This operation is only required in case when security violation detected."
                echo "It is your responsibility to update server list information on all other servers."
                echo -n "Do you really need to generate new secret key? (y/N) "
                read CONFIRM

                if [ "${CONFIRM}" == "y" -o "${CONFIRM}" == "Y" ]; then
                    CONFIRM=1
                    break
                elif [ "${CONFIRM}" == "" -o "${CONFIRM}" == "n" -o "${CONFIRM}" == "N" ]; then
                    CONFIRM=0
                    break
                fi
            done
        else
            CONFIRM=1
        fi

        if [ ${CONFIRM} -eq 1 ]; then
            mysql -u root -D ngos -e "UPDATE properties SET value='${SECRET_KEY}' WHERE name='secret_key';" || return 1
        else
            echo "Canceled"

            return 1
        fi
    fi



    echo "Secret key:"
    echo "${SECRET_KEY}"



    return 0
}



function assign_secret_key
{
    SERVER=$1

    if [ "${SERVER}" == "" ]; then
        while true
        do
            clear



            echo "Assign secret key to server:"

            OPTION_NUM=1

            for SERVER in `mysql -u root -D ngos -NB -e "SELECT address FROM servers;"`
            do
                SERVER_LENGTH=${#SERVER}

                echo -n "[${OPTION_NUM}] ${SERVER}"
                printf "%$((60 - SERVER_LENGTH))s" ""
                mysql -u root -D ngos -NB -e "SELECT secret_key FROM servers WHERE address='${SERVER}';" | cut -c -20

                OPTIONS[${OPTION_NUM}]=${SERVER}
                OPTION_NUM=$((${OPTION_NUM} + 1))
            done

            echo ""
            echo "[0] Cancel"
            OPTIONS[0]="~~~CANCEL~~~"



            echo ""
            echo -n "Option: "
            read SELECTED_OPTION



            SERVER=${OPTIONS[${SELECTED_OPTION}]}

            if [ "${SERVER}" != "" ]; then
                break
            fi
        done



        if [ "${SERVER}" == "~~~CANCEL~~~" ]; then
            echo "Canceled"

            return 1
        fi
    fi



    SECRET_KEY=$2
    SECRET_KEY=`echo "${SECRET_KEY}" | tr -dc "a-zA-Z0-9"`

    while [ ${#SECRET_KEY} -ne 1000 ];
    do
        echo -n "Enter secret key for ${SERVER}: "
        read SECRET_KEY

        SECRET_KEY=`echo "${SECRET_KEY}" | tr -dc "a-zA-Z0-9"`

        if [ ${#SECRET_KEY} -ne 1000 ]; then
            echo "Invalid secret key"
        fi
    done



    mysql -u root -D ngos -e "UPDATE servers SET secret_key='${SECRET_KEY}' WHERE address='${SERVER}';" || return 1



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
    SERVER_NAME=`mysql -u root -D ngos -NB -e "SELECT value FROM properties WHERE name='server_name';"`

    if [ "${SERVER_NAME}" == "" ]; then
        echo "Server name is invalid. Please specify new server name"

        return 1
    fi



    MY_SECRET_KEY=`mysql -u root -D ngos -NB -e "SELECT value FROM properties WHERE name='secret_key';" | tr -dc "a-zA-Z0-9"`

    if [ ${#MY_SECRET_KEY} -ne 1000 ]; then
        echo "Secret key is invalid. Please generate new secret key"

        return 1
    fi



    SERVER=$1

    if [ "${SERVER}" == "" ]; then
        while [ "${SERVER}" == "" ];
        do
            echo -n "Enter server name: "
            read SERVER
        done
    fi



    if [ "${SERVER}" == "${SERVER_NAME}" ]; then
        echo "${SERVER} is the localhost"

        return 1
    fi



    SECRET_KEY=$2
    SECRET_KEY=`echo "${SECRET_KEY}" | tr -dc "a-zA-Z0-9"`

    while [ ${#SECRET_KEY} -ne 1000 ];
    do
        echo -n "Enter secret key for ${SERVER}: "
        read SECRET_KEY

        SECRET_KEY=`echo "${SECRET_KEY}" | tr -dc "a-zA-Z0-9"`

        if [ ${#SECRET_KEY} -ne 1000 ]; then
            echo "Invalid secret key"
        fi
    done



    SERVER_ID=`mysql -u root -D ngos -NB -e "SELECT id FROM servers WHERE address='${SERVER}';"`

    if [ "${SERVER_ID}" == "" ]; then
        mysql -u root -D ngos -e "INSERT INTO servers (address, secret_key) VALUES ('${SERVER}', '${SECRET_KEY}');" || return 1
    else
        mysql -u root -D ngos -e "UPDATE servers SET secret_key='${SECRET_KEY}' WHERE address='${SERVER}';" || return 1
    fi



    for ADDRESS in `mysql -u root -D ngos -NB -e "SELECT address FROM servers WHERE address!='${SERVER}' AND address!='${SERVER_NAME}';"`
    do
        REQUEST_DATA=`cat << EOF
            {
                "my_address":    "${SERVER_NAME}",
                "address":       "${ADDRESS}",
                "my_secret_key": "${MY_SECRET_KEY}",
                "secret_key":    "${SECRET_KEY}"
            }
EOF
        `

        echo "${REQUEST_DATA}" | curl -k -X POST -H "Content-Type: application/json" -d @- "https://${SERVER}/rest/register.php"
        echo ""
    done



    echo "Server ${SERVER} registered"

    return 0
}



function change_server_location
{
    echo "TBD"

    return 0
}



function update_server_delays
{
    for SERVER in `mysql -u root -D ngos -NB -e "SELECT address FROM servers;"`
    do
        echo "Updating delay to server: ${SERVER}"



        PING_TOTAL=0

        for ((i = 0; i < 10; i++))
        do
            PING_RESPONSE=`curl -k -s -w "%{time_total}" https://${SERVER}/rest/ping.php`

            if [ "${PING_RESPONSE:0:15}" != "{\"status\":\"OK\"}" ]; then
                echo "Failed to ping server: ${SERVER}"

                exit 1
            fi

            PING_TOTAL=`echo "${PING_TOTAL} + ${PING_RESPONSE:15}" | bc`
        done

        DELAY=`echo "${PING_TOTAL} * 100000 / 1" | bc`



        mysql -u root -D ngos -e "UPDATE servers SET delay='${DELAY}' WHERE address='${SERVER}';" || return 1
    done



    return 0
}



function validate_setup
{
    if [ ! -f /var/www/html/rest/deploy.php ]; then
        echo "NGOS webapp not installed"

        return 1
    fi



    SERVER_NAME=`mysql -u root -D ngos -NB -e "SELECT value FROM properties WHERE name='server_name';"`

    if [ "${SERVER_NAME}" == "" ]; then
        echo "Server name is invalid. Please specify new server name"

        return 1
    fi



    SECRET_KEY=`mysql -u root -D ngos -NB -e "SELECT value FROM properties WHERE name='secret_key';" | tr -dc "a-zA-Z0-9"`

    if [ ${#SECRET_KEY} -ne 1000 ]; then
        echo "Secret key is invalid. Please generate new secret key"

        return 1
    fi



    INVALID_SERVERS=`mysql -u root -D ngos -NB -e "SELECT address FROM servers WHERE secret_key IS NULL OR LENGTH(secret_key) != 1000;"`

    if [ "${INVALID_SERVERS}" != "" ]; then
        echo "Servers with invalid secret keys:"
        echo "${INVALID_SERVERS}"

        echo ""
        echo "Please assign valid secret keys"

        return 1
    fi



    echo "Everything is OK"

    return 0
}



function print_server_name
{
    echo "Server name:"
    mysql -u root -D ngos -NB -e "SELECT value FROM properties WHERE name='server_name';" || return 1

    return 0
}



function print_secret_key
{
    echo "Secret key:"
    mysql -u root -D ngos -NB -e "SELECT value FROM properties WHERE name='secret_key';" || return 1

    return 0
}



function print_servers
{
    echo "Servers:"
    mysql -u root -D ngos -e "SELECT t1.id, t1.address, t2.name as region, t1.delay, SUBSTRING(t1.secret_key, 1, 20) as secret_key FROM servers AS t1 INNER JOIN regions as t2 ON t1.region_id = t2.id;" || return 1

    return 0
}



function uninstall_sources
{
    if [ -d /var/www/html ]; then
        if [ ${SILENT_MODE} -eq 0 ]; then
            while true
            do
                echo "This operation will remove all NGOS webapp sources and all NGOS applications stored on this server."
                echo -n "Do you really want to uninstall NGOS webapp sources? (y/N) "
                read CONFIRM

                if [ "${CONFIRM}" == "y" -o "${CONFIRM}" == "Y" ]; then
                    CONFIRM=1
                    break
                elif [ "${CONFIRM}" == "" -o "${CONFIRM}" == "n" -o "${CONFIRM}" == "N" ]; then
                    CONFIRM=0
                    break
                fi
            done
        else
            CONFIRM=1
        fi

        if [ ${CONFIRM} -eq 1 ]; then
            rm -rf /var/www/html || return 1

            echo "NGOS webapp sources uninstalled"
        else
            echo "Canceled"

            return 1
        fi
    else
        echo "Directory \"/var/www/html\" not found"

        return 1
    fi



    return 0
}



function drop_database
{
    if [ ${SILENT_MODE} -eq 0 ]; then
        while true
        do
            echo "This operation will remove all data stored in NGOS database."
            echo -n "Do you really want to drop NGOS database? (y/N) "
            read CONFIRM

            if [ "${CONFIRM}" == "y" -o "${CONFIRM}" == "Y" ]; then
                CONFIRM=1
                break
            elif [ "${CONFIRM}" == "" -o "${CONFIRM}" == "n" -o "${CONFIRM}" == "N" ]; then
                CONFIRM=0
                break
            fi
        done
    else
        CONFIRM=1
    fi

    if [ ${CONFIRM} -eq 1 ]; then
        mysql -u root -e "DROP DATABASE ngos" || return 1

        echo "NGOS database dropped"
    else
        echo "Canceled"

        return 1
    fi



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
    ATTRS[0]=""

    TEXT[1]="Setup server name"
    FUNC[1]="setup_server_name"
    ATTRS[1]="NAME"

    TEXT[2]="Generate server secret key"
    FUNC[2]="generate_secret_key"
    ATTRS[2]=""

    TEXT[3]="Assign secret key to server"
    FUNC[3]="assign_secret_key"
    ATTRS[3]="SERVER SECRET_KEY"

    return 0
}



function step2_options()
{
    TITLE="Common stuff"

    TEXT[0]="Update webapp sources"
    FUNC[0]="update_sources"
    ATTRS[0]=""

    TEXT[1]="Register new server"
    FUNC[1]="register_server"
    ATTRS[1]="SERVER SECRET_KEY"

    TEXT[2]="Change server location"
    FUNC[2]="change_server_location"
    ATTRS[2]="SERVER REGION"

    TEXT[3]="Update server delays"
    FUNC[3]="update_server_delays"
    ATTRS[3]=""

    return 0
}



function step3_options()
{
    TITLE="Verification"

    TEXT[0]="Validate setup"
    FUNC[0]="validate_setup"
    ATTRS[0]=""

    TEXT[1]="Print server name"
    FUNC[1]="print_server_name"
    ATTRS[1]=""

    TEXT[2]="Print secret key"
    FUNC[2]="print_secret_key"
    ATTRS[2]=""

    TEXT[3]="Print servers"
    FUNC[3]="print_servers"
    ATTRS[3]=""

    return 0
}



function step4_options()
{
    TITLE="Uninstall"

    TEXT[0]="Uninstall webapp sources"
    FUNC[0]="uninstall_sources"
    ATTRS[0]=""

    TEXT[1]="Drop database"
    FUNC[1]="drop_database"
    ATTRS[1]=""

    return 0
}



function display_menu
{
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
            unset ATTRS
        done

        echo "[0] Exit"
        OPTIONS[0]="quit"



        echo ""
        echo -n "Option: "
        read SELECTED_OPTION

        COMMAND=${OPTIONS[${SELECTED_OPTION}]}



        if [ "${COMMAND}" != "" ]; then
            echo ""
            ${COMMAND}
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
        fi
    done



    return 0
}



function usage()
{
    echo -n "Usage: sudo ./setup.sh"

    for ((s = 0; s < ${STEPS_COUNT}; s++))
    do
        ${STEPS[s]} || return 1



        OPTIONS_COUNT=${#TEXT[@]}

        for ((i = 0; i < ${OPTIONS_COUNT}; i++))
        do
            echo -n " [--${FUNC[i]}"

            if [ "${ATTRS[i]}" != "" ]; then
                echo -n " ${ATTRS[i]}"
            fi

            echo -n "]"
        done



        unset TEXT
        unset FUNC
        unset ATTRS
    done

    echo ""
    echo ""



    for ((s = 0; s < ${STEPS_COUNT}; s++))
    do
        ${STEPS[s]} || return 1



        OPTIONS_COUNT=${#TEXT[@]}

        for ((i = 0; i < ${OPTIONS_COUNT}; i++))
        do
            FUNC_ATTRS=`echo "--${FUNC[i]} ${ATTRS[i]}"`
            FUNC_ATTRS_LENGTH=${#FUNC_ATTRS}

            echo -n "    ${FUNC_ATTRS}"
            printf "%$((40 - FUNC_ATTRS_LENGTH))s" ""
            echo " - ${TEXT[i]}"
        done



        unset TEXT
        unset FUNC
        unset ATTRS
    done



    return 0
}



function script_mode()
{
    while true
    do
        COMMAND=$1

        if [ "${COMMAND}" == "" ]; then
            break
        fi

        if [ "${COMMAND}" == "-h" -o "${COMMAND}" == "--help" ]; then
            usage || return 1

            return 0
        fi



        ATTRS=()

        while true
        do
            ATTR=$2

            if [ "${ATTR}" == "" ]; then
                break
            fi

            if [ "${ATTR}" == "-h" -o "${ATTR:0:2}" == "--" ]; then
                break
            fi

            ATTRS+=($ATTR)

            shift
        done

        ${COMMAND:2} ${ATTRS[@]}



        shift
    done



    return 0
}



###########################################################################################
#    PROCESSING
###########################################################################################



if [ ${SILENT_MODE} -eq 0 ]; then
    display_menu || exit 1
else
    script_mode $@ || exit 1
fi



exit 0
