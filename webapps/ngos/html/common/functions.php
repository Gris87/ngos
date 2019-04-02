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



    function get_property_value($link, $data, $name)
    {
        $res = "";



        $sql = "SELECT"
            . "     value"
            . " FROM " . $GLOBALS["DB_TABLE_PROPERTIES"]
            . " WHERE name='" . $link->real_escape_string($name) . "'";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        if ($result->num_rows == 1)
        {
            $res = $result->fetch_row()[0];
            $result->close();
        }
        else
        {
            $result->close();



            $error_details = "Access violation";
            error_log($error_details);

            db_disconnect($link);

            $data["message"] = "Access error";
            $data["details"] = $error_details;

            die(json_encode($data));
        }



        return $res;
    }



    function set_property_value($link, $data, $name, $value)
    {
        $sql = "SELECT"
            . "     value"
            . " FROM " . $GLOBALS["DB_TABLE_PROPERTIES"]
            . " WHERE name='" . $link->real_escape_string($name) . "'";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        if ($result->num_rows == 1)
        {
            $sql = "UPDATE " . $GLOBALS["DB_TABLE_PROPERTIES"]
                . " SET value='"  . $link->real_escape_string($value) . "'"
                . " WHERE name='" . $link->real_escape_string($name)  . "'";
        }
        else
        {
            $sql = "INSERT INTO " . $GLOBALS["DB_TABLE_PROPERTIES"]
                . " (name, value)"
                . " VALUES("
                . "  '" . $link->real_escape_string($name)  . "',"
                . "  '" . $link->real_escape_string($value) . "'"
                . ")";
        }

        $result->close();



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);
    }



    function get_server_name($link, $data)
    {
        return get_property_value($link, $data, "server_name");
    }



    function get_secret_key($link, $data)
    {
        return get_property_value($link, $data, "secret_key");
    }



    function get_region_id($link, $data)
    {
        return get_property_value($link, $data, "region_id");
    }



    function set_region_id($link, $data, $value)
    {
        return set_property_value($link, $data, "region_id", $value);
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
            $result->close();
        }
        else
        {
            $result->close();



            $error_details = "Access violation";
            error_log($error_details);

            db_disconnect($link);

            $data["message"] = "Access error";
            $data["details"] = $error_details;

            die(json_encode($data));
        }



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
