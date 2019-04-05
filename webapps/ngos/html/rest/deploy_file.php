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
            unlink($path);



            $error_details = "Invalid parameters";
            error_log($error_details);

            db_disconnect($link);

            $data["message"] = "File broken";
            $data["details"] = $error_details;

            die(json_encode($data));
        }
    }



    function avoid_duplicate_file($link, $data, $download_name, $path, $hash)
    {
        $sql = "SELECT"
            . "     download_name"
            . " FROM " . DB_TABLE_APP_FILES
            . " WHERE hash = '" . $link->real_escape_string($hash) . "'";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        $files = [];

        while ($row = $result->fetch_row())
        {
            array_push($files, $row[0]);
        }

        $result->close();



        foreach ($files as $file)
        {
            $another_path = "../downloads/" . $file;

            $output    = [];
            $exit_code = 0;

            exec("diff " . $path . " " . $another_path, $output, $exit_code);

            if ($exit_code == 0)
            {
                unlink($path);

                return $file;
            }
        }



        return $download_name;
    }



    function create_download_file($link, $data, $compression_method, $hash, $content)
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



        $download_name = generate_download_name($compression_method);
        $path          = "../downloads/" . $download_name;

        if (!file_exists("../downloads"))
        {
            mkdir("../downloads");
        }

        file_put_contents($path, $file_content);



        check_file_hash($link, $data, $path, $hash);



        return avoid_duplicate_file($link, $data, $download_name, $path, $hash);
    }



    function create_app_file_id($link, $data, $app_version_id, $filename, $download_name, $hash)
    {
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



        return $link->insert_id;
    }



    function replicate_file($link, $data, $app_file_id, $app_version_id, $app_id, $filename, $download_name, $hash, $content, $secret_key)
    {
        $replicate_data = [
            "app_file_id"    => $app_file_id,
            "app_version_id" => $app_version_id,
            "app_id"         => $app_id,
            "filename"       => $filename,
            "download_name"  => $download_name,
            "hash"           => $hash,
            "content"        => $content,
            "secret_key"     => $secret_key
        ];

        replicate($link, $data, $replicate_data, "/rest/replicate_file.php");
    }



    function handle_post_with_params($link, $data, $app_id, $app_version_id, $filename, $compression_method, $hash, $content, $secret_key)
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



        $download_name = create_download_file($link, $data, $compression_method, $hash, $content);
        $app_file_id   = create_app_file_id($link, $data, $app_version_id, $filename, $download_name, $hash);

        replicate_file($link, $data, $app_file_id, $app_version_id, $app_id, $filename, $download_name, $hash, $content, $secret_key);
    }



    function handle_post()
    {
        header("Content-type: application/json");

        $data =
        [
            "status" => "Failed"
        ];



        $_POST = json_decode(file_get_contents("php://input"), true);



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
