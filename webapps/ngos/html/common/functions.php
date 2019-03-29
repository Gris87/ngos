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



    function get_secret_key($link, $data)
    {
        $res = "";



        $sql = "SELECT"
            . "     value"
            . " FROM " . $GLOBALS["DB_TABLE_PROPERTIES"]
            . " WHERE name='secret_key'";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        if ($result->num_rows == 1)
        {
            $res = $result->fetch_row()[0];
        }

        $result->close();



        return $res;
    }



    function get_server_secret_key($link, $data, $address)
    {
        $res = "";



        $sql = "SELECT"
            . "     secret_key"
            . " FROM " . $GLOBALS["DB_TABLE_SERVERS"]
            . " WHERE address='" . $link->real_escape_string($address) . "'";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        if ($result->num_rows == 1)
        {
            $res = $result->fetch_row()[0];
        }

        $result->close();



        return $res;
    }



    function validate_server($link, $data, $address, $secret_key)
    {
        if (get_server_secret_key($link, $data, $address) != $secret_key)
        {
            $error_details = "Access violation";
            error_log($error_details);

            db_disconnect($link);

            $data["message"] = "Access error";
            $data["details"] = $error_details;

            die(json_encode($data));
        }
    }



    function validate_this_server($link, $data, $secret_key)
    {
        if (get_secret_key($link, $data) != $secret_key)
        {
            $error_details = "Access violation";
            error_log($error_details);

            db_disconnect($link);

            $data["message"] = "Access error";
            $data["details"] = $error_details;

            die(json_encode($data));
        }
    }
?>
