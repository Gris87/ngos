<?php
    require_once "constants.php";



    define("SECRET_KEY_REGEXP", "/^[\\w\\d]{1000,1000}$/");
    define("CODENAME_REGEXP",   "/^[a-z][a-z\\d_]*(\\.[a-z][a-z\\d_]*){2,}$/");



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
            . " WHERE name = '" . $link->real_escape_string($name) . "'";



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
            . " WHERE name = '" . $link->real_escape_string($name) . "'";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        if ($result->num_rows == 1)
        {
            $sql = "UPDATE " . $GLOBALS["DB_TABLE_PROPERTIES"]
                . " SET value = '"  . $link->real_escape_string($value) . "'"
                . " WHERE name = '" . $link->real_escape_string($name)  . "'";
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
            . " WHERE address = '" . $link->real_escape_string($address) . "'";



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



    function validate_access($link, $data, $my_address, $my_secret_key, $your_secret_key)
    {
        validate_server($link, $data, $my_address, $my_secret_key);
        validate_this_server($link, $data, $your_secret_key);
    }



    function validate_server_with_ping($link, $data, $my_address, $my_secret_key, $address, $secret_key)
    {
        $server_url = "https://" . $address . "/rest/ping.php";



        $request_data = [
            "my_address"      => $my_address,
            "my_secret_key"   => $my_secret_key,
            "your_secret_key" => $secret_key
        ];



        $curl_session = curl_init($server_url);

        curl_setopt($curl_session, CURLOPT_CONNECTTIMEOUT, 10);
        curl_setopt($curl_session, CURLOPT_HEADER,         false);
        curl_setopt($curl_session, CURLOPT_RETURNTRANSFER, true);
        curl_setopt($curl_session, CURLOPT_SSL_VERIFYHOST, 0);
        curl_setopt($curl_session, CURLOPT_SSL_VERIFYPEER, 0);
        curl_setopt($curl_session, CURLOPT_CUSTOMREQUEST,  "POST");
        curl_setopt($curl_session, CURLOPT_HTTPHEADER,     array("Content-Type: application/json"));
        curl_setopt($curl_session, CURLOPT_POSTFIELDS,     json_encode($request_data));

        $response = curl_exec($curl_session);
        curl_close($curl_session);



        if ($response)
        {
            $response = json_decode($response, true);

            if ($response["status"] != "OK")
            {
                $error_details = "Failed to parse response from server: " . $server_url;
                error_log($error_details);

                db_disconnect($link);

                $data["message"] = "Request error";
                $data["details"] = $error_details;

                die(json_encode($data));
            }
        }
        else
        {
            $error_details = "Failed to get response from server: " . $server_url;
            error_log($error_details);

            db_disconnect($link);

            $data["message"] = "Request error";
            $data["details"] = $error_details;

            die(json_encode($data));
        }
    }



    function get_delay_to_server($link, $data, $address)
    {
        $server_url = "https://" . $address . "/rest/ping.php";



        $curl_multi    = curl_multi_init();
        $curl_sessions = [];

        for ($i = 0; $i < 10; ++$i)
        {
            $curl_session = curl_init($server_url);

            curl_setopt($curl_session, CURLOPT_CONNECTTIMEOUT, 10);
            curl_setopt($curl_session, CURLOPT_HEADER,         false);
            curl_setopt($curl_session, CURLOPT_RETURNTRANSFER, true);
            curl_setopt($curl_session, CURLOPT_SSL_VERIFYHOST, 0);
            curl_setopt($curl_session, CURLOPT_SSL_VERIFYPEER, 0);

            curl_multi_add_handle($curl_multi, $curl_session);
            array_push($curl_sessions, $curl_session);
        }



        $active = false;

        do
        {
            $status = curl_multi_exec($curl_multi, $active);

            if ($active)
            {
                curl_multi_select($curl_multi);
            }
        } while ($active && $status == CURLM_OK);



        $responses  = [];
        $ping_total = 0;

        foreach ($curl_sessions as $curl_session)
        {
            array_push($responses, curl_multi_getcontent($curl_session));
            $ping_total += curl_getinfo($curl_session, CURLINFO_TOTAL_TIME);
        }



        foreach ($curl_sessions as $curl_session)
        {
            curl_multi_remove_handle($curl_multi, $curl_session);
            curl_close($curl_session);
        }

        curl_multi_close($curl_multi);



        foreach ($responses as $response)
        {
            if ($response)
            {
                $response = json_decode($response, true);

                if ($response["status"] != "OK")
                {
                    $error_details = "Failed to parse response from server: " . $server_url;
                    error_log($error_details);

                    db_disconnect($link);

                    $data["message"] = "Request error";
                    $data["details"] = $error_details;

                    die(json_encode($data));
                }
            }
            else
            {
                $error_details = "Failed to get response from server: " . $server_url;
                error_log($error_details);

                db_disconnect($link);

                $data["message"] = "Request error";
                $data["details"] = $error_details;

                die(json_encode($data));
            }
        }



        return $ping_total * 100000;
    }



    function verify_address($address)
    {
        return isset($address)
               &&
               is_string($address)
               &&
               (
                filter_var($address, FILTER_VALIDATE_IP) != false
                ||
                filter_var($address, FILTER_VALIDATE_DOMAIN, FILTER_FLAG_HOSTNAME) != false
               );
    }



    function verify_secret_key($secret_key)
    {
        return isset($secret_key)
               &&
               is_string($secret_key)
               &&
               preg_match(constant("SECRET_KEY_REGEXP"), $secret_key);
    }



    function verify_region_id($region_id)
    {
        return isset($region_id)
               &&
               is_int($region_id)
               &&
               $region_id > 0;
    }



    function verify_codename($codename)
    {
        return isset($codename)
               &&
               is_string($codename)
               &&
               preg_match(constant("CODENAME_REGEXP"), $codename);
    }



    function verify_version($version)
    {
        return isset($version)
               &&
               is_int($version)
               &&
               $version > 20190101000000;
    }



    function verify_vendor_id($vendor_id)
    {
        return isset($vendor_id)
               &&
               is_int($vendor_id)
               &&
               $vendor_id > 0;
    }



    function verify_email($email)
    {
        return isset($email)
               &&
               is_string($email)
               &&
               filter_var($email, FILTER_VALIDATE_EMAIL) != false;
    }



    function verify_name($name)
    {
        return isset($name)
               &&
               is_string($name)
               &&
               $name != "";
    }
?>
