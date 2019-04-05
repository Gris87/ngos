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



    function handle_post_with_params($link, $data, $app_id, $app_version_id, $filename, $compression_method, $hash, $content, $secret_key)
    {
        if (get_server_name($link, $data) != "10.83.230.9")
        {
            $error_details = "Access violation";
            error_log($error_details);

            db_disconnect($link);

            $data["message"] = "Access error";
            $data["details"] = $error_details;

            die(json_encode($data));
        }



        validate_app_secret_key($link, $data, $app_id, $secret_key);



        $file_content = base64_decode($content, true);

        if (!$file_content)
        {
            $error_details = "Access violation";
            error_log($error_details);

            db_disconnect($link);

            $data["message"] = "Access error";
            $data["details"] = $error_details;

            die(json_encode($data));
        }



        if (!file_exists("../downloads"))
        {
            mkdir("../downloads");
        }

        $download_name = generate_download_name($compression_method);
        file_put_contents("../downloads/" . $download_name, $file_content);



        $sql = "INSERT INTO " . DB_TABLE_APP_FILES
            . " (app_version_id, filename, download_name, hash)"
            . " VALUES("
            . "  '" . $link->real_escape_string($app_version_id) . "',"
            . "  '" . $link->real_escape_string($filename)       . "',"
            . "  '" . $link->real_escape_string($download_name)  . "',"
            . "  '" . $link->real_escape_string($hash)           . "'"
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



        $app_id             = @$_POST["app_id"];
        $app_version_id     = @$_POST["app_version_id"];
        $filename           = @$_POST["filename"];
        $compression_method = @$_POST["compression_method"];
        $hash               = @$_POST["hash"];
        $content            = @$_POST["content"];
        $secret_key         = @$_POST["secret_key"];



        if (
            !verify_app_id($app_id)
            ||
            !verify_app_version_id($app_version_id)
            ||
            !verify_filename($filename)
            ||
            !verify_compression_method($compression_method)
            ||
            !verify_hash($hash)
            ||
            !verify_content($content)
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
            handle_post_with_params($link, $data, $app_id, $app_version_id, $filename, $compression_method, $hash, $content, $secret_key);

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
