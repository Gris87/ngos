#!/bin/bash

# This script helps to install webapps prerequisites on Ubuntu 20.10
# Author: Maxim Shvecov
# Usage: sudo ./ubuntu_20_10.sh



###########################################################################################
#    VERIFICATION
###########################################################################################



if [ ${EUID} -ne 0 ]; then
    echo "Please run as root"

    exit 1
fi



if [[ "`lsb_release -rs`" != "20.10" ]]; then
    echo "This script should be called on Ubuntu 20.10"

    exit 1
fi



###########################################################################################
#    PROCESSING
###########################################################################################



echo ""
echo -e "\e[33m-------------------- Environment --------------------\e[0m"
echo ""



apt-get update
apt-get upgrade -y

apt-get install -y jq



echo ""
echo -e "\e[33m-------------------- apache2 --------------------\e[0m"
echo ""



apt-get install -y apache2

systemctl start apache2
systemctl enable apache2



echo ""
echo -e "\e[33m-------------------- mariadb --------------------\e[0m"
echo ""



apt-get install -y mariadb-server mariadb-client

systemctl start mariadb
systemctl enable mariadb

mysql_secure_installation << EOF

n
Y
Y
Y
Y
EOF



echo ""
echo -e "\e[33m-------------------- php --------------------\e[0m"
echo ""



apt-get install -y php libapache2-mod-php php-common php-mbstring php-xmlrpc php-soap php-gd php-xml php-intl php-mysql php-cli php-zip php-curl



echo ""
echo -e "\e[33m-------------------- SSL setup --------------------\e[0m"
echo ""



apt-get install -y ssl-cert
make-ssl-cert generate-default-snakeoil --force-overwrite

a2enmod ssl
a2enmod rewrite
a2ensite default-ssl



echo ""
echo -e "\e[33m-------------------- Clean up --------------------\e[0m"
echo ""



sed -i "s/Options Indexes/Options/g"              /etc/apache2/apache2.conf
sed -i "s/AllowOverride None/AllowOverride All/g" /etc/apache2/apache2.conf

rm /var/www/html/index.html 2> /dev/null



systemctl restart apache2



echo ""
echo -e "\e[32m-------------------- Done --------------------\e[0m"
echo ""
