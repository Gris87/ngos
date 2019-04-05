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



    function check_file_hash($link, $data, $path, $hash)
    {
        $own_hash = calculate_download_file_hash($path);

        if ($own_hash != $hash)
        {
            $error_details = "Invalid parameters";
            error_log($error_details);

            db_disconnect($link);

            $data["message"] = "File broken";
            $data["details"] = $error_details;

            die(json_encode($data));
        }
    }



    function create_download_file($link, $data, $download_name, $hash, $content)
    {
        $file_content = base64_decode($content, true);

        if (!$file_content)
        {
            $error_details = "Invalid parameters";
            error_log($error_details);

            db_disconnect($link);

            $data["message"] = "File broken";
            $data["details"] = $error_details;

            die(json_encode($data));
        }



        $path = "../downloads/" . $download_name;

        if (!file_exists($path))
        {
            if (!file_exists("../downloads"))
            {
                mkdir("../downloads");
            }

            file_put_contents($path, $file_content);
        }
        else
        {
            check_file_hash($link, $data, $path, $hash);
        }
    }



    function insert_app_file($link, $data, $app_file_id, $app_version_id, $filename, $download_name, $hash)
    {
        $sql = "INSERT INTO " . DB_TABLE_APP_FILES
            . " (id, app_version_id, filename, download_name, hash)"
            . " VALUES("
            . "  '" . $link->real_escape_string($app_file_id)    . "',"
            . "  '" . $link->real_escape_string($app_version_id) . "',"
            . "  '" . $link->real_escape_string($filename)       . "',"
            . "  '" . $link->real_escape_string($download_name)  . "',"
            . "  '" . $link->real_escape_string($hash)           . "'"
            . ")";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);
    }



    function forward_message_to_another_servers($link, $data, $level, $my_address, $my_secret_key, $app_file_id, $app_version_id, $app_id, $filename, $download_name, $hash, $content, $secret_key)
    {
        switch ($level)
        {
            case 0:
            {
                $replicate_data = [
                    "my_address"     => $my_address,
                    "my_secret_key"  => $my_secret_key,
                    "app_file_id"    => $app_file_id,
                    "app_version_id" => $app_version_id,
                    "app_id"         => $app_id,
                    "filename"       => $filename,
                    "download_name"  => $download_name,
                    "hash"           => $hash,
                    "content"        => $content,
                    "secret_key"     => $secret_key
                ];

                $region_id = get_region_id($link, $data);



                replicate_by_region($link, $data, $replicate_data, "/rest/replicate_file.php", $region_id, $my_address);
            }
            break;

            case 1:
            {
                // Nothing
            }
            break;

            default:
            {
                die("Unknown level");
            }
        }
    }



    function handle_post_with_params($link, $data, $level, $my_address, $my_secret_key, $your_secret_key, $app_file_id, $app_version_id, $app_id, $filename, $download_name, $hash, $content, $secret_key)
    {
        validate_access($link, $data, $my_address, $my_secret_key, $your_secret_key);

        validate_app_secret_key($link, $data, $app_id, $secret_key);
        validate_app_version($link, $data, $app_version_id);



        create_download_file($link, $data, $download_name, $hash, $content);
        insert_app_file($link, $data, $app_file_id, $app_version_id, $filename, $download_name, $hash);



        $own_address = get_server_name($link, $data);

        forward_message_to_another_servers($link, $data, $level, $own_address, $your_secret_key, $app_file_id, $app_version_id, $app_id, $filename, $download_name, $hash, $content, $secret_key);
    }



    function handle_post()
    {
        header("Content-type: application/json");

        $data =
        [
            "status" => "Failed"
        ];



        $_POST = json_decode(file_get_contents("php://input"), true);



        $level           = @$_POST["level"];
        $my_address      = @$_POST["my_address"];
        $my_secret_key   = @$_POST["my_secret_key"];
        $your_secret_key = @$_POST["your_secret_key"];
        $app_file_id     = @$_POST["app_file_id"];
        $app_version_id  = @$_POST["app_version_id"];
        $app_id          = @$_POST["app_id"];
        $filename        = @$_POST["filename"];
        $download_name   = @$_POST["download_name"];
        $hash            = @$_POST["hash"];
        $content         = @$_POST["content"];
        $secret_key      = @$_POST["secret_key"];



        if (
            !verify_level($level)
            ||
            !verify_address($my_address)
            ||
            !verify_secret_key($my_secret_key)
            ||
            !verify_secret_key($your_secret_key)
            ||
            !verify_app_file_id($app_file_id)
            ||
            !verify_app_version_id($app_version_id)
            ||
            !verify_app_id($app_id)
            ||
            !verify_filename($filename)
            ||
            !verify_download_name($download_name)
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
            handle_post_with_params($link, $data, $level, $my_address, $my_secret_key, $your_secret_key, $app_file_id, $app_version_id, $app_id, $filename, $download_name, $hash, $content, $secret_key);

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
