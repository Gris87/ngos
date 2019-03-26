CREATE DATABASE IF NOT EXISTS ngos default character set latin1;
GRANT ALL PRIVILEGES ON ngos.* to ngos@localhost IDENTIFIED BY "ngos";

use ngos;



CREATE TABLE IF NOT EXISTS apps
(
    id BIGINT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    appid BIGINT NOT NULL,
    codename VARCHAR(256) NOT NULL,
    name VARCHAR(256) NOT NULL,
    version BIGINT NOT NULL
) engine=InnoDB default character set latin1;



CREATE TABLE IF NOT EXISTS properties
(
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(256) NOT NULL UNIQUE,
    value VARCHAR(1024) NOT NULL
) engine=InnoDB default character set latin1;



CREATE TABLE IF NOT EXISTS servers
(
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    address VARCHAR(256) NOT NULL UNIQUE,
    secret_key VARCHAR(1024) NULL
) engine=InnoDB default character set latin1;
