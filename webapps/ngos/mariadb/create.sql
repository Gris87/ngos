CREATE DATABASE IF NOT EXISTS ngos default character set utf8 default collate utf8_general_ci;

use ngos;



CREATE TABLE IF NOT EXISTS apps
(
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    appid INT NOT NULL,
    codename VARCHAR(256) NOT NULL,
    name VARCHAR(256) NOT NULL,
    version INT NOT NULL
) engine=InnoDB default character set utf8 default collate utf8_general_ci;



CREATE TABLE IF NOT EXISTS properties
(
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(256) NOT NULL,
    value VARCHAR(256) NOT NULL
) engine=InnoDB default character set utf8 default collate utf8_general_ci;



CREATE TABLE IF NOT EXISTS servers
(
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    address VARCHAR(256) NOT NULL
) engine=InnoDB default character set utf8 default collate utf8_general_ci;
