<?php
    require_once "../common/functions.php";



    function handle_request()
    {
        switch ($_SERVER["REQUEST_METHOD"])
        {
            case "GET":
            {
                handle_get();
            }
            break;

            case "POST":
            {
                handle_post();
            }
            break;

            default:
            {
                die("Unknown method");
            }
        }
    }



    function handle_get()
    {
        // Nothing
    }



    function verify_server_with_ping($link, $data, $my_address, $my_secret_key, $address, $secret_key)
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



    function handle_post_with_params($link, $data, $my_address, $my_secret_key, $your_secret_key, $region_id, $address, $secret_key)
    {
        validate_server($link, $data, $my_address, $my_secret_key);
        validate_this_server($link, $data, $your_secret_key);



        $own_address    = get_server_name($link, $data);
        $own_secret_key = get_secret_key($link, $data);

        verify_server_with_ping($link, $data, $own_address, $own_secret_key, $address, $secret_key);



        $delay = get_delay_to_server($link, $data, $address);



        if ($own_address == $address && $own_secret_key == $secret_key)
        {
            set_region_id($link, $data, $region_id);
        }



        $sql = "INSERT INTO " . $GLOBALS["DB_TABLE_SERVERS"]
            . " (region_id, address, delay, secret_key)"
            . " VALUES("
            . "  '" . $link->real_escape_string($region_id)  . "',"
            . "  '" . $link->real_escape_string($address)    . "',"
            . "  '" . $link->real_escape_string($delay)      . "',"
            . "  '" . $link->real_escape_string($secret_key) . "'"
            . ")";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);
    }



    function handle_post()
    {
        header("Content-type: application/json");

        $data =
        [
            "status" => "Failed"
        ];



        $_POST = json_decode(file_get_contents('php://input'), true);



        $my_address      = @$_POST["my_address"];
        $my_secret_key   = @$_POST["my_secret_key"];
        $your_secret_key = @$_POST["your_secret_key"];
        $region_id       = @$_POST["region_id"];
        $address         = @$_POST["address"];
        $secret_key      = @$_POST["secret_key"];

        if (
            !isset($my_address)
            ||
            !isset($my_secret_key)
            ||
            !isset($your_secret_key)
            ||
            !isset($region_id)
            ||
            !isset($address)
            ||
            !isset($secret_key)
            ||
            !is_string($my_address)
            ||
            !is_string($my_secret_key)
            ||
            !is_string($your_secret_key)
            ||
            !is_int($region_id)
            ||
            !is_string($address)
            ||
            !is_string($secret_key)
            ||
            $my_address == ""
            ||
            strlen($my_secret_key) != 1000
            ||
            strlen($your_secret_key) != 1000
            ||
            $region_id <= 0
            ||
            $address == ""
            ||
            strlen($secret_key) != 1000
           )
        {
            $data["message"] = "Invalid parameters";

            die(json_encode($data));
        }



        $link = db_connect();

        if ($link)
        {
            handle_post_with_params($link, $data, $my_address, $my_secret_key, $your_secret_key, $region_id, $address, $secret_key);

            db_disconnect($link);
        }
        else
        {
            $data["message"] = "Database connection error";

            die(json_encode($data));
        }



        $data["status"] = "OK";
        echo json_encode($data);
    }



    handle_request();
?>
