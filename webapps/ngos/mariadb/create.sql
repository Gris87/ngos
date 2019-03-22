CREATE TABLE servers IF NOT EXISTS
(
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    address varchar(256) NOT NULL
) engine=InnoDB default charset utf8;
