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



    function add_servers_from_address($link, $data, $address, &$servers)
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



            $another_servers = $response["servers"];

            foreach ($another_servers as $server)
            {
                if (!in_array($server, $servers))
                {
                    array_push($servers, $server);

                    add_servers_from_address($link, $data, $server, $servers);
                }
            }
        }
        else
        {
            error_log("Failed to get response from server: " . $server_url);
        }
    }



    function insert_server_to_db($link, $data, $address)
    {
        $sql = "INSERT INTO " . $GLOBALS["DB_TABLE_SERVERS"]
            . " (address)"
            . " VALUES("
            . "  '" . $link->real_escape_string($address) . "'"
            . ")";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);
    }



    function handle_post_not_internal($link, $data)
    {
        $sql = "SELECT"
            . "     address"
            . " FROM " . $GLOBALS["DB_TABLE_SERVERS"];



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        $servers = [];

        while ($row = $result->fetch_row())
        {
            array_push($servers, $row[0]);
        }

        $result->close();



        $original_servers = $servers;

        foreach ($original_servers as $server)
        {
            add_servers_from_address($link, $data, $server, $servers);
        }



        foreach ($servers as $server)
        {
            if (!in_array($server, $original_servers))
            {
                insert_server_to_db($link, $data, $server);
            }
        }
    }



    function handle_post_internal($link, $data)
    {
        insert_server_to_db($link, $data, $_SERVER["REMOTE_ADDR"]);
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
            $data["message"] = "Database connection error";

            die(json_encode($data));
        }



        $data["status"] = "OK";
        echo json_encode($data);
    }
?>
