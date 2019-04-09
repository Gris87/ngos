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



    function complete_version($link, &$data, $app_id, $app_version_id)
    {
        $hash = calculate_app_version_hash($link, $data, $app_version_id);



        if (avoid_duplicate_version($link, $data, $app_id, $hash))
        {
            $sql = "UPDATE " . DB_TABLE_APP_VERSIONS
                . " SET hash      = '" . $link->real_escape_string($hash) . "',"
                . "     completed = '1'"
                . " WHERE id = '" . $link->real_escape_string($app_version_id) . "'";



            $result = $link->query($sql);
            die_if_sql_failed($result, $link, $data, $sql);
        }
        else
        {
            $data["ignored"] = true;
        }



        return $hash;
    }



    function replicate_complete_version($link, $data, $app_id, $app_version_id, $hash, $secret_key)
    {
        $replicate_data = [
            "app_id"         => $app_id,
            "app_version_id" => $app_version_id,
            "hash"           => $hash,
            "secret_key"     => $secret_key
        ];

        replicate($link, $data, $replicate_data, "/rest/replicate_complete_version.php");
    }



    function handle_post_with_params($link, &$data, $app_id, $app_version_id, $secret_key)
    {
        if (get_server_name($link, $data) != MASTER_SERVER)
        {
            $error_details = "Access violation";
            error_log($error_details);

            db_disconnect($link);

            $data["message"] = "Access error";
            $data["details"] = $error_details;

            die(json_encode($data));
        }



        validate_app_secret_key($link, $data, $app_id, $secret_key);
        validate_app_version($link, $data, $app_version_id);



        $hash = complete_version($link, $data, $app_id, $app_version_id);

        replicate_complete_version($link, $data, $app_id, $app_version_id, $hash, $secret_key);
    }



    function handle_post()
    {
        header("Content-type: application/json");

        $data =
        [
            "status" => "Failed"
        ];



        $_POST = json_decode(file_get_contents("php://input"), true);



        $app_id         = @$_POST["app_id"];
        $app_version_id = @$_POST["app_version_id"];
        $secret_key     = @$_POST["secret_key"];



        if (
            !verify_app_id($app_id)
            ||
            !verify_app_version_id($app_version_id)
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
            handle_post_with_params($link, $data, $app_id, $app_version_id, $secret_key);

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
