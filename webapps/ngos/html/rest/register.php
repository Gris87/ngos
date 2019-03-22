<?php
    require_once "../common/functions.php";



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
    
    
    
    function handle_get()
    {
        // Nothing
    }



    function add_servers_from_address($link, $data, $address)
    {
        $server_url = "https://" . $address . "/rest/servers.php";



        $curlSession = curl_init($server_url);

        curl_setopt($curlSession, CURLOPT_CONNECTTIMEOUT, 10);
        curl_setopt($curlSession, CURLOPT_HEADER,         false);
        curl_setopt($curlSession, CURLOPT_RETURNTRANSFER, true);
        curl_setopt($curlSession, CURLOPT_SSL_VERIFYHOST, 0);
        curl_setopt($curlSession, CURLOPT_SSL_VERIFYPEER, 0);

        $response = curl_exec($curlSession);
        curl_close($curlSession);



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

            var_dump($response);
        }
        else
        {
            error_log("Failed to get response from server: " . $server_url);
        }
    }



    function handle_post_not_internal($link, $data)
    {
        $sql = "SELECT"
            . "     address"
            . " FROM " . $GLOBALS["DB_TABLE_SERVERS"];



        $result = $link->query($sql);

        if (!$result)
        {
            $error_details = "SQL Failed: " . $sql . " Error: " . $link->error;
            error_log($error_details);

            db_disconnect($link);

            $data["message"] = "Database error";
            $data["details"] = $error_details;

            die(json_encode($data));
        }



        while ($row = $result->fetch_row())
        {
            add_servers_from_address($link, $data, $row[0]);
        }



        $result->close();
    }



    function handle_post_internal($link, $data)
    {
        $sql = "INSERT INTO " . $GLOBALS["DB_TABLE_SERVERS"]
            . " (address)"
            . " VALUES("
            . "  '" . $link->real_escape_string($_SERVER["REMOTE_ADDR"]) . "'"
            . ")";



        $result = $link->query($sql);

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



    function handle_post()
    {
        header("Content-type: application/json");

        $data =
        [
            "status" => "Failed"
        ];



        $_POST = json_decode(file_get_contents("php://input"), true);



        $internal = @$_POST["internal"];

        if (isset($internal))
        {
            if (!is_bool($internal))
            {
                $data["message"] = "Invalid parameters";

                die(json_encode($data));
            }
        }
        else
        {
            $internal = false;
        }



        $link = db_connect();

        if ($link)
        {
            if (!$internal)
            {
                handle_post_not_internal($link, $data);
            }
            else
            {
                handle_post_internal($link, $data);
            }



            db_disconnect($link);
        }
        else
        {
            $data["message"] = "Database error";

            die(json_encode($data));
        }



        $data["status"] = "OK";
        echo json_encode($data);
    }
?>
