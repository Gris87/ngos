<?php
    require_once "constants.php";



    define("CODENAME_REGEXP",      "/^[a-z][a-z\\d_]*(\\.[a-z][a-z\\d_]*){2,}$/");
    define("DOWNLOAD_NAME_REGEXP", "/^[\\w\\d]{249,249}\\.\\d{1,2}\\.(raw|xz)$/");
    define("MD5_HASH_REGEXP",      "/^[0-9a-f]{32,32}$/");
    define("SECRET_KEY_REGEXP",    "/^[\\w\\d]{1000,1000}$/");



    function db_connect()
    {
        $link = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);

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
            . " FROM " . DB_TABLE_PROPERTIES
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



            $error_details = "Invalid server state";
            error_log($error_details);

            db_disconnect($link);

            $data["message"] = "Internal error";
            $data["details"] = $error_details;

            die(json_encode($data));
        }



        return $res;
    }



    function set_property_value($link, $data, $name, $value)
    {
        $sql = "SELECT"
            . "     value"
            . " FROM " . DB_TABLE_PROPERTIES
            . " WHERE name = '" . $link->real_escape_string($name) . "'";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        if ($result->num_rows == 1)
        {
            $sql = "UPDATE " . DB_TABLE_PROPERTIES
                . " SET value = '"  . $link->real_escape_string($value) . "'"
                . " WHERE name = '" . $link->real_escape_string($name)  . "'";
        }
        else
        {
            $sql = "INSERT INTO " . DB_TABLE_PROPERTIES
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
            . " FROM " . DB_TABLE_SERVERS
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
                $error_details = "Invalid response from server " . $server_url . " : " . json_encode($response);
                error_log($error_details);

                db_disconnect($link);

                $data["message"] = "Request error";
                $data["details"] = $error_details;

                die(json_encode($data));
            }
        }
        else
        {
            $error_details = "Failed to get response from server " . $server_url;
            error_log($error_details);

            db_disconnect($link);

            $data["message"] = "Request error";
            $data["details"] = $error_details;

            die(json_encode($data));
        }
    }



    function validate_app_secret_key($link, $data, $app_id, $secret_key)
    {
        $sql = "SELECT"
            . "     secret_key"
            . " FROM " . DB_TABLE_APPS
            . " WHERE id = '" . $link->real_escape_string($app_id) . "'";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        if ($result->num_rows == 1)
        {

            $app_secret_key = $result->fetch_row()[0];

            $result->close();



            if ($secret_key != $app_secret_key)
            {
                $error_details = "Access violation";
                error_log($error_details);

                db_disconnect($link);

                $data["message"] = "Access error";
                $data["details"] = $error_details;

                die(json_encode($data));
            }
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
    }



    function validate_app_version($link, $data, $app_version_id)
    {
        $sql = "SELECT"
            . "     completed"
            . " FROM " . DB_TABLE_APP_VERSIONS
            . " WHERE id = '" . $link->real_escape_string($app_version_id) . "'";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        if ($result->num_rows == 1)
        {
            $completed = $result->fetch_row()[0];

            $result->close();



            if ($completed != 0)
            {
                $error_details = "Invalid version state";
                error_log($error_details);

                db_disconnect($link);

                $data["message"] = "Internal error";
                $data["details"] = $error_details;

                die(json_encode($data));
            }
        }
        else
        {
            $result->close();



            $error_details = "Invalid server state";
            error_log($error_details);

            db_disconnect($link);

            $data["message"] = "Internal error";
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
                    $error_details = "Invalid response from server " . $server_url . " : " . json_encode($response);
                    error_log($error_details);

                    db_disconnect($link);

                    $data["message"] = "Request error";
                    $data["details"] = $error_details;

                    die(json_encode($data));
                }
            }
            else
            {
                $error_details = "Failed to get response from server " . $server_url;
                error_log($error_details);

                db_disconnect($link);

                $data["message"] = "Request error";
                $data["details"] = $error_details;

                die(json_encode($data));
            }
        }



        return round($ping_total * 100000);
    }



    function replicate_to_regions($link, $data, $replicate_data, $path, $region_id)
    {
        $sql = "SELECT"
            . "     region_id,"
            . "     address,"
            . "     delay,"
            . "     secret_key"
            . " FROM " . DB_TABLE_SERVERS
            . " WHERE region_id != '" . $link->real_escape_string($region_id) . "'"
            . " ORDER BY region_id";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        $last_region_id     = -1;
        $min_delay          = 0;
        $preferable_servers = [];

        while ($row = $result->fetch_assoc())
        {
            $cur_region_id = $row["region_id"];
            $delay         = $row["delay"];

            if ($last_region_id != $cur_region_id)
            {
                $last_region_id                     = $cur_region_id;
                $min_delay                          = $delay;
                $preferable_servers[$cur_region_id] = $row;
            }
            else
            {
                if ($delay < $min_delay)
                {
                    $min_delay                          = $delay;
                    $preferable_servers[$cur_region_id] = $row;
                }
            }
        }

        $result->close();



        $curl_multi = curl_multi_init();



        $replicate_data["level"] = 0;

        foreach ($preferable_servers as &$server)
        {
            $replicate_data["your_secret_key"] = $server["secret_key"];



            $curl_session = curl_init("https://" . $server["address"] . $path);

            curl_setopt($curl_session, CURLOPT_CONNECTTIMEOUT, 10);
            curl_setopt($curl_session, CURLOPT_HEADER,         false);
            curl_setopt($curl_session, CURLOPT_RETURNTRANSFER, true);
            curl_setopt($curl_session, CURLOPT_SSL_VERIFYHOST, 0);
            curl_setopt($curl_session, CURLOPT_SSL_VERIFYPEER, 0);
            curl_setopt($curl_session, CURLOPT_CUSTOMREQUEST,  "POST");
            curl_setopt($curl_session, CURLOPT_HTTPHEADER,     array("Content-Type: application/json"));
            curl_setopt($curl_session, CURLOPT_POSTFIELDS,     json_encode($replicate_data));

            curl_multi_add_handle($curl_multi, $curl_session);
            $server["curl_session"] = $curl_session;
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



        foreach ($preferable_servers as &$server)
        {
            $curl_session = $server["curl_session"];

            $server["response"] = curl_multi_getcontent($curl_session);

            curl_multi_remove_handle($curl_multi, $curl_session);
            curl_close($curl_session);
        }

        curl_multi_close($curl_multi);



        foreach ($preferable_servers as $server)
        {
            $response = $server["response"];

            if ($response)
            {
                $response = json_decode($response, true);

                if ($response["status"] != "OK")
                {
                    $error_details = "Invalid response from server https://" . $server["address"] . $path . " : " . json_encode($response);
                    error_log($error_details);

                    db_disconnect($link);

                    $data["message"] = "Request error";
                    $data["details"] = $error_details;

                    die(json_encode($data));
                }
            }
            else
            {
                $error_details = "Failed to get response from server https://" . $server["address"] . $path;
                error_log($error_details);

                db_disconnect($link);

                $data["message"] = "Request error";
                $data["details"] = $error_details;

                die(json_encode($data));
            }
        }
    }



    function replicate_by_region($link, $data, $replicate_data, $path, $region_id, $my_address)
    {
        $sql = "SELECT"
            . "     address,"
            . "     secret_key"
            . " FROM " . DB_TABLE_SERVERS
            . " WHERE"
            . "     region_id =  '" . $link->real_escape_string($region_id)  . "'"
            . "     AND"
            . "     address   != '" . $link->real_escape_string($my_address) . "'";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        $servers = [];

        while ($row = $result->fetch_assoc())
        {
            array_push($servers, $row);
        }

        $result->close();



        if (count($servers) > 0)
        {
            $curl_multi = curl_multi_init();



            $replicate_data["level"] = 1;

            foreach ($servers as &$server)
            {
                $replicate_data["your_secret_key"] = $server["secret_key"];



                $curl_session = curl_init("https://" . $server["address"] . $path);

                curl_setopt($curl_session, CURLOPT_CONNECTTIMEOUT, 10);
                curl_setopt($curl_session, CURLOPT_HEADER,         false);
                curl_setopt($curl_session, CURLOPT_RETURNTRANSFER, true);
                curl_setopt($curl_session, CURLOPT_SSL_VERIFYHOST, 0);
                curl_setopt($curl_session, CURLOPT_SSL_VERIFYPEER, 0);
                curl_setopt($curl_session, CURLOPT_CUSTOMREQUEST,  "POST");
                curl_setopt($curl_session, CURLOPT_HTTPHEADER,     array("Content-Type: application/json"));
                curl_setopt($curl_session, CURLOPT_POSTFIELDS,     json_encode($replicate_data));

                curl_multi_add_handle($curl_multi, $curl_session);
                $server["curl_session"] = $curl_session;
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



            foreach ($servers as &$server)
            {
                $curl_session = $server["curl_session"];

                $server["response"] = curl_multi_getcontent($curl_session);

                curl_multi_remove_handle($curl_multi, $curl_session);
                curl_close($curl_session);
            }

            curl_multi_close($curl_multi);



            foreach ($servers as $server)
            {
                $response = $server["response"];

                if ($response)
                {
                    $response = json_decode($response, true);

                    if ($response["status"] != "OK")
                    {
                        $error_details = "Invalid response from server https://" . $server["address"] . $path . " : " . json_encode($response);
                        error_log($error_details);

                        db_disconnect($link);

                        $data["message"] = "Request error";
                        $data["details"] = $error_details;

                        die(json_encode($data));
                    }
                }
                else
                {
                    $error_details = "Failed to get response from server https://" . $server["address"] . $path;
                    error_log($error_details);

                    db_disconnect($link);

                    $data["message"] = "Request error";
                    $data["details"] = $error_details;

                    die(json_encode($data));
                }
            }
        }
    }



    function replicate($link, $data, $replicate_data, $path)
    {
        $my_address    = get_server_name($link, $data);
        $my_secret_key = get_secret_key($link, $data);
        $region_id     = get_region_id($link, $data);



        $replicate_data["my_address"]    = $my_address;
        $replicate_data["my_secret_key"] = $my_secret_key;



        replicate_to_regions($link, $data, $replicate_data, $path, $region_id);
        replicate_by_region($link, $data, $replicate_data, $path, $region_id, $my_address);
    }



    function endsWith($haystack, $needle)
    {
        $length = strlen($needle);

        if ($length == 0)
        {
            return true;
        }

        return substr($haystack, -$length) === $needle;
    }



    function random_string($length, $keyspace = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")
    {
        $res = "";

        $max = strlen($keyspace) - 1;

        for ($i = 0; $i < $length; ++$i)
        {
            $res .= $keyspace[random_int(0, $max)];
        }

        return $res;
    }



    function generate_download_name($compression_method)
    {
        do
        {
            $res = random_string(249);

            switch ($compression_method)
            {
                case 0:
                {
                    $res .= ".0.raw";
                }
                break;

                case 1:
                {
                    $res .= ".0.xz";
                }
                break;

                default:
                {
                    die("Unknown compression method");
                }
            }

            if (!file_exists("../downloads/" . $res))
            {
                return $res;
            }
        } while(true);
    }



    function calculate_download_file_hash($path)
    {
        if (endsWith($path, ".raw"))
        {
            return exec("md5sum " . $path . " | awk '{ print $1 }'");
        }
        else
        if (endsWith($path, ".xz"))
        {
            return exec("cat " . $path . " | unxz | md5sum | awk '{ print $1 }'");
        }



        return "";
    }



    function calculate_app_version_hash($link, $data, $app_version_id)
    {
        $sql = "SELECT"
            . "     hash"
            . " FROM " . DB_TABLE_APP_FILES
            . " WHERE app_version_id = '" . $link->real_escape_string($app_version_id) . "'";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        if ($result->num_rows == 0)
        {
            $result->close();



            $error_details = "Version is empty";
            error_log($error_details);

            db_disconnect($link);

            $data["message"] = "Internal error";
            $data["details"] = $error_details;

            die(json_encode($data));
        }



        $res = pack("H*", "00000000000000000000000000000000");

        while ($row = $result->fetch_row())
        {
            $res ^= pack("H*", $row[0]);
        }

        $result->close();



        return bin2hex($res);
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



    function verify_app_id($app_id)
    {
        return isset($app_id)
               &&
               is_int($app_id)
               &&
               $app_id > 0;
    }



    function verify_app_file_id($app_file_id)
    {
        return isset($app_file_id)
               &&
               is_int($app_file_id)
               &&
               $app_file_id > 0;
    }



    function verify_app_version_id($app_version_id)
    {
        return isset($app_version_id)
               &&
               is_int($app_version_id)
               &&
               $app_version_id > 0;
    }



    function verify_codename($codename)
    {
        return isset($codename)
               &&
               is_string($codename)
               &&
               preg_match(CODENAME_REGEXP, $codename);
    }



    function verify_compression_method($compression_method)
    {
        return isset($compression_method)
               &&
               is_int($compression_method)
               &&
               $compression_method >= 0
               &&
               $compression_method <= 1;
    }



    function verify_content($content)
    {
        return isset($content)
               &&
               is_string($content)
               &&
               $content != "";
    }



    function verify_download_name($download_name)
    {
        return isset($download_name)
               &&
               is_string($download_name)
               &&
               preg_match(DOWNLOAD_NAME_REGEXP, $download_name);
    }



    function verify_email($email)
    {
        return isset($email)
               &&
               is_string($email)
               &&
               filter_var($email, FILTER_VALIDATE_EMAIL) != false;
    }



    function verify_filename($filename)
    {
        return isset($filename)
               &&
               is_string($filename)
               &&
               $filename != "";
    }



    function verify_hash($hash)
    {
        return isset($hash)
               &&
               is_string($hash)
               &&
               preg_match(MD5_HASH_REGEXP, $hash);
    }



    function verify_level($level)
    {
        return isset($level)
               &&
               is_int($level)
               &&
               $level >= 0
               &&
               $level <= 1;
    }



    function verify_name($name)
    {
        return isset($name)
               &&
               is_string($name)
               &&
               $name != "";
    }



    function verify_region_id($region_id)
    {
        return isset($region_id)
               &&
               is_int($region_id)
               &&
               $region_id > 0;
    }



    function verify_secret_key($secret_key)
    {
        return isset($secret_key)
               &&
               is_string($secret_key)
               &&
               preg_match(SECRET_KEY_REGEXP, $secret_key);
    }



    function verify_vendor_id($vendor_id)
    {
        return isset($vendor_id)
               &&
               is_int($vendor_id)
               &&
               $vendor_id > 0;
    }



    function verify_version($version)
    {
        return isset($version)
               &&
               is_int($version)
               &&
               $version >= 20190101000000;
    }



    function verify_version_for_user($version)
    {
        return isset($version)
               &&
               is_int($version)
               &&
               $version >= 20190101;
    }
?>
