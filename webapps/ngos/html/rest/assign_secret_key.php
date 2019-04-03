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



    function handle_post_with_params($link, $data, $my_address, $my_secret_key, $your_secret_key, $address, $secret_key)
    {
        $own_address = get_server_name($link, $data);

        if ($own_address == $address)
        {
            validate_access($link, $data, $my_address, $my_secret_key, $secret_key);
        }
        else
        {
            $own_secret_key = get_secret_key($link, $data);
            
            validate_access($link, $data, $my_address, $my_secret_key, $your_secret_key);
            validate_server_with_ping($link, $data, $own_address, $own_secret_key, $address, $secret_key);
        }



        $sql = "UPDATE " . $GLOBALS["DB_TABLE_SERVERS"]
            . " SET secret_key = '" . $link->real_escape_string($secret_key) . "'"
            . " WHERE address = '"  . $link->real_escape_string($address)    . "'";



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
        $address         = @$_POST["address"];
        $secret_key      = @$_POST["secret_key"];

        if (
            !verify_address($my_address)
            ||
            !verify_secret_key($my_secret_key)
            ||
            !verify_secret_key($your_secret_key)
            ||
            !verify_address($address)
            ||
            !verify_secret_key($secret_key)
           )
        {
            $data["message"] = "Invalid parameters";

            die(json_encode($data));
        }



        $link = db_connect();

        if ($link)
        {
            handle_post_with_params($link, $data, $my_address, $my_secret_key, $your_secret_key, $address, $secret_key);

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
