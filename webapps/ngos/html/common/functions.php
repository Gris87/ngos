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



    function die_if_sql_failed($result, $link, $data, $sql)
    {
        if (!$result)
        {
            $error_details = "SQL Failed: " . $sql . " Error: " . $link->error;
            error_log($error_details);

            db_disconnect($link);

            $data["message"] = "Database error";
            $data["details"] = $error_details;

            die(json_encode($data));
        }
    }
?>
