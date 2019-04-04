CREATE DATABASE IF NOT EXISTS ngos default character set latin1;
GRANT ALL PRIVILEGES ON ngos.* to ngos@localhost IDENTIFIED BY "ngos";

use ngos;



CREATE TABLE IF NOT EXISTS vendors
(
    id BIGINT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(256) NOT NULL UNIQUE,
    password_crypted VARCHAR(256) NOT NULL
) engine=InnoDB default character set latin1;



CREATE TABLE IF NOT EXISTS apps
(
    id BIGINT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    vendor_id BIGINT NOT NULL,
    codename VARCHAR(256) NOT NULL UNIQUE,
    owner_email VARCHAR(256) NOT NULL,
    name VARCHAR(256) NOT NULL,
    description VARCHAR(1024) NOT NULL,
    secret_key VARCHAR(1024) NOT NULL,
    CONSTRAINT `fk_vendor_to_app`
        FOREIGN KEY (vendor_id) REFERENCES vendors (id)
        ON DELETE RESTRICT
        ON UPDATE RESTRICT
) engine=InnoDB default character set latin1;



CREATE TABLE IF NOT EXISTS app_versions
(
    id BIGINT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    app_id BIGINT NOT NULL,
    version BIGINT NOT NULL,
    hash VARCHAR(32) NOT NULL,
    completed BOOLEAN NOT NULL,
    CONSTRAINT `fk_app_to_version`
        FOREIGN KEY (app_id) REFERENCES apps (id)
        ON DELETE RESTRICT
        ON UPDATE RESTRICT
) engine=InnoDB default character set latin1;



CREATE TABLE IF NOT EXISTS app_files
(
    id BIGINT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    app_version_id BIGINT NOT NULL,
    filename VARCHAR(256) NOT NULL,
    download_name VARCHAR(256) NOT NULL,
    hash VARCHAR(32) NOT NULL,
    CONSTRAINT `fk_app_version_to_file`
        FOREIGN KEY (app_version_id) REFERENCES app_versions (id)
        ON DELETE RESTRICT
        ON UPDATE RESTRICT
) engine=InnoDB default character set latin1;



CREATE TABLE IF NOT EXISTS properties
(
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(256) NOT NULL UNIQUE,
    value VARCHAR(1024) NOT NULL
) engine=InnoDB default character set latin1;



CREATE TABLE IF NOT EXISTS regions
(
    id INT NOT NULL PRIMARY KEY,
    name VARCHAR(256) NOT NULL UNIQUE
) engine=InnoDB default character set latin1;



CREATE TABLE IF NOT EXISTS servers
(
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    region_id INT NOT NULL,
    address VARCHAR(256) NOT NULL UNIQUE,
    delay INT NOT NULL,
    secret_key VARCHAR(1024) NULL,
    CONSTRAINT `fk_region_to_server`
        FOREIGN KEY (region_id) REFERENCES regions (id)
        ON DELETE RESTRICT
        ON UPDATE RESTRICT
) engine=InnoDB default character set latin1;
