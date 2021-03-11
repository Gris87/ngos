#!/bin/bash                                                                                                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
# This script helps to install webapps prerequisites on Ubuntu 20.10                                                                                                                                     # Colorize: green
# Author: Maxim Shvecov                                                                                                                                                                                  # Colorize: green
# Usage: sudo ./ubuntu_20_10.sh                                                                                                                                                                          # Colorize: green
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
if [[ `lsb_release -rs` != 20.10 ]]; then                                                                                                                                                                # Colorize: green
    echo "This script should be called on Ubuntu 20.10"                                                                                                                                                  # Colorize: green
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
echo ""                                                                                                                                                                                                  # Colorize: green
echo -e "\e[33m-------------------- Environment --------------------\e[0m"                                                                                                                               # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
apt-get update                                                                                                                                                                                           # Colorize: green
apt-get upgrade -y                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
apt-get install -y jq                                                                                                                                                                                    # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
echo -e "\e[33m-------------------- apache2 --------------------\e[0m"                                                                                                                                   # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
apt-get install -y apache2                                                                                                                                                                               # Colorize: green
                                                                                                                                                                                                         # Colorize: green
systemctl start apache2                                                                                                                                                                                  # Colorize: green
systemctl enable apache2                                                                                                                                                                                 # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
echo -e "\e[33m-------------------- mariadb --------------------\e[0m"                                                                                                                                   # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
apt-get install -y mariadb-server mariadb-client                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
systemctl start mariadb                                                                                                                                                                                  # Colorize: green
systemctl enable mariadb                                                                                                                                                                                 # Colorize: green
                                                                                                                                                                                                         # Colorize: green
mysql_secure_installation << EOF                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
n                                                                                                                                                                                                        # Colorize: green
Y                                                                                                                                                                                                        # Colorize: green
Y                                                                                                                                                                                                        # Colorize: green
Y                                                                                                                                                                                                        # Colorize: green
Y                                                                                                                                                                                                        # Colorize: green
EOF                                                                                                                                                                                                      # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
echo -e "\e[33m-------------------- php --------------------\e[0m"                                                                                                                                       # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
apt-get install -y php libapache2-mod-php php-common php-mbstring php-xmlrpc php-soap php-gd php-xml php-intl php-mysql php-cli php-zip php-curl                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
echo -e "\e[33m-------------------- SSL setup --------------------\e[0m"                                                                                                                                 # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
apt-get install -y ssl-cert                                                                                                                                                                              # Colorize: green
make-ssl-cert generate-default-snakeoil --force-overwrite                                                                                                                                                # Colorize: green
                                                                                                                                                                                                         # Colorize: green
a2enmod ssl                                                                                                                                                                                              # Colorize: green
a2enmod rewrite                                                                                                                                                                                          # Colorize: green
a2ensite default-ssl                                                                                                                                                                                     # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
echo -e "\e[33m-------------------- Clean up --------------------\e[0m"                                                                                                                                  # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
sed -i "s/Options Indexes/Options/g"              /etc/apache2/apache2.conf                                                                                                                              # Colorize: green
sed -i "s/AllowOverride None/AllowOverride All/g" /etc/apache2/apache2.conf                                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
rm /var/www/html/index.html 2> /dev/null                                                                                                                                                                 # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
systemctl restart apache2                                                                                                                                                                                # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
echo -e "\e[32m-------------------- Done --------------------\e[0m"                                                                                                                                      # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
