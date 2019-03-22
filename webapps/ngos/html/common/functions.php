<?php
    require_once "constants.php";



    function db_connect()
    {
        $link = new mysqli($GLOBALS["DB_HOST"], $GLOBALS["DB_USER"], $GLOBALS["DB_PASSWORD"], $GLOBALS["DB_NAME"]);

        if ($link->connect_error)
        {
            error_log("Failed to connect to MariaDB server. Error: " . $link->connect_error);

            return null;
        }

        return $link;
    }



    function db_disconnect($link)
    {
        $link->close();
    }
?>
