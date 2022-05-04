#!/bin/bash
                                                                                                                                                                                                         # Colorize: green
# This script helps to install NGOS webapp                                                                                                                                                               # Colorize: green
# Author: Maxim Shvetsov                                                                                                                                                                                  # Colorize: green
# Usage: sudo ./install.sh                                                                                                                                                                               # Colorize: green
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
MASTER_SERVER=cps-etl-srv.northeurope.cloudapp.azure.com                                                                                                                                                 # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
#    VERIFICATION                                                                                                                                                                                        # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
if [ ${EUID} -ne 0 ]; then                                                                                                                                                                               # Colorize: green
    echo "Please run as root"                                                                                                                                                                            # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    exit 1                                                                                                                                                                                               # Colorize: green
fi                                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
APACHE_VERSION=`apache2 -v`                                                                                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
if [ "${APACHE_VERSION}" == "" ]; then                                                                                                                                                                   # Colorize: green
    cd ../prerequisites/                                                                                                                                                                                 # Colorize: green
    ./install.sh                                                                                                                                                                                         # Colorize: green
    cd ${CURRENT_PATH}                                                                                                                                                                                   # Colorize: green
fi                                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
#    FUNCTIONS                                                                                                                                                                                           # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
function ping_server                                                                                                                                                                                     # Colorize: green
{                                                                                                                                                                                                        # Colorize: green
    SERVER=$1                                                                                                                                                                                            # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    curl -k -s -w "%{time_total}" https://${SERVER}/rest/ping.php || return 1                                                                                                                            # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    return 0                                                                                                                                                                                             # Colorize: green
}                                                                                                                                                                                                        # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
function execute_sql                                                                                                                                                                                     # Colorize: green
{                                                                                                                                                                                                        # Colorize: green
    SQL=$1                                                                                                                                                                                               # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    mysql -u root -D ngos -e "${SQL}" || return 1                                                                                                                                                        # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    return 0                                                                                                                                                                                             # Colorize: green
}                                                                                                                                                                                                        # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
function execute_sql_without_header                                                                                                                                                                      # Colorize: green
{                                                                                                                                                                                                        # Colorize: green
    SQL=$1                                                                                                                                                                                               # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    mysql -u root -D ngos -NB -e "${SQL}" || return 1                                                                                                                                                    # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    return 0                                                                                                                                                                                             # Colorize: green
}                                                                                                                                                                                                        # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
#    PROCESSING                                                                                                                                                                                          # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
cp -r html/. /var/www/html                                                                                                                                                                               # Colorize: green
chown -R www-data:www-data /var/www/html                                                                                                                                                                 # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
mysql -u root < mariadb/create.sql || exit 1                                                                                                                                                             # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
execute_sql "INSERT IGNORE INTO regions (id, name) VALUES ('1', 'Russia / Saint-Petersburg');" || exit 1                                                                                                 # Colorize: green
execute_sql "INSERT IGNORE INTO regions (id, name) VALUES ('2', 'Russia / Moscow');"           || exit 1                                                                                                 # Colorize: green
execute_sql "INSERT IGNORE INTO regions (id, name) VALUES ('3', 'Ireland');"                   || exit 1                                                                                                 # Colorize: green
                                                                                                                                                                                                         # Colorize: green
execute_sql "INSERT IGNORE INTO vendors (name, password_crypted) VALUES ('NGOS', '');" || exit 1                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
FIRST_SERVER=`execute_sql_without_header "SELECT id FROM servers WHERE address = '${MASTER_SERVER}';"`                                                                                                   # Colorize: green
                                                                                                                                                                                                         # Colorize: green
if [ "${FIRST_SERVER}" == "" ]; then                                                                                                                                                                     # Colorize: green
    PING_TOTAL=0                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    for ((i = 0; i < 10; i++))                                                                                                                                                                           # Colorize: green
    do                                                                                                                                                                                                   # Colorize: green
        PING_RESPONSE=`ping_server ${MASTER_SERVER}`                                                                                                                                                     # Colorize: green
                                                                                                                                                                                                         # Colorize: green
        if [ "${PING_RESPONSE:0:15}" != "{\"status\":\"OK\"}" ]; then                                                                                                                                    # Colorize: green
            echo "Failed to ping server ${MASTER_SERVER}: ${PING_RESPONSE}"                                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
            exit 1                                                                                                                                                                                       # Colorize: green
        fi                                                                                                                                                                                               # Colorize: green
                                                                                                                                                                                                         # Colorize: green
        PING_TOTAL=`echo "${PING_TOTAL} + ${PING_RESPONSE:15}" | bc`                                                                                                                                     # Colorize: green
    done                                                                                                                                                                                                 # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    DELAY=`echo "${PING_TOTAL} * 100000 / 1" | bc`                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    execute_sql "INSERT INTO servers (region_id, address, delay) VALUES ('3', '${MASTER_SERVER}', '${DELAY}');" || exit 1                                                                                # Colorize: green
fi                                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
exit 0                                                                                                                                                                                                   # Colorize: green
