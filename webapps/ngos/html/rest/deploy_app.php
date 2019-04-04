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



    function get_or_create_app_id($link, $data, $vendor_id, $codename, $owner_email, $name, $secret_key)
    {
        $res = 0;



        $sql = "SELECT"
            . "     id,"
            . "     secret_key"
            . " FROM " . DB_TABLE_APPS
            . " WHERE codename = '" . $link->real_escape_string($codename) . "'";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        if ($result->num_rows == 0)
        {
            $result->close();



            if (
                !verify_vendor_id($vendor_id)
                ||
                !verify_email($owner_email)
                ||
                !verify_name($name)
               )
            {
                db_disconnect($link);

                $data["message"] = "Invalid parameters";

                die(json_encode($data));
            }



            $sql = "INSERT INTO " . DB_TABLE_APPS
                . " (vendor_id, codename, owner_email, name, description, secret_key)"
                . " VALUES("
                . "  '" . $link->real_escape_string($vendor_id)   . "',"
                . "  '" . $link->real_escape_string($codename)    . "',"
                . "  '" . $link->real_escape_string($owner_email) . "',"
                . "  '" . $link->real_escape_string($name)        . "',"
                . "  '',"
                . "  '" . $link->real_escape_string($secret_key)  . "'"
                . ")";



            $result2 = $link->query($sql);
            die_if_sql_failed($result2, $link, $data, $sql);



            $res = $link->insert_id;
        }
        else
        {
            $row = $result->fetch_assoc();

            $res            = (int)$row["id"];
            $app_secret_key = $row["secret_key"];

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



        return $res;
    }



    function create_app_version_id($link, $data, $app_id, $version)
    {
        $sql = "INSERT INTO " . DB_TABLE_APP_VERSIONS
            . " (app_id, version, hash, completed)"
            . " VALUES("
            . "  '" . $link->real_escape_string($app_id)  . "',"
            . "  '" . $link->real_escape_string($version) . "',"
            . "  '00000000000000000000000000000000',"
            . "  '0'"
            . ")";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        return $link->insert_id;
    }



    function replicate_app($link, $data, $app_id, $vendor_id, $codename, $owner_email, $name, $secret_key)
    {
        $replicate_data = [
            "app_id"      => $app_id,
            "vendor_id"   => $vendor_id,
            "codename"    => $codename,
            "owner_email" => $owner_email,
            "name"        => $name,
            "secret_key"  => $secret_key
        ];

        replicate($link, $data, $replicate_data, "/rest/replicate_app.php");
    }



    function replicate_app_version($link, $data, $app_version_id, $app_id, $version, $secret_key)
    {
        $replicate_data = [
            "app_version_id" => $app_version_id,
            "app_id"         => $app_id,
            "version"        => $version,
            "secret_key"     => $secret_key
        ];

        replicate($link, $data, $replicate_data, "/rest/replicate_app_version.php");
    }



    function handle_post_with_params($link, &$data, $vendor_id, $codename, $owner_email, $name, $version, $secret_key)
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



        $app_id = get_or_create_app_id($link, $data, $vendor_id, $codename, $owner_email, $name, $secret_key);
        replicate_app($link, $data, $app_id, $vendor_id, $codename, $owner_email, $name, $secret_key);

        $app_version_id = create_app_version_id($link, $data, $app_id, $version);
        replicate_app_version($link, $data, $app_version_id, $app_id, $version, $secret_key);



        $data["app_id"]         = $app_id;
        $data["app_version_id"] = $app_version_id;
    }



    function handle_post()
    {
        header("Content-type: application/json");

        $data =
        [
            "status" => "Failed"
        ];



        $_POST = json_decode(file_get_contents('php://input'), true);



        $vendor_id   = @$_POST["vendor_id"];
        $codename    = @$_POST["codename"];
        $owner_email = @$_POST["owner_email"];
        $name        = @$_POST["name"];
        $version     = @$_POST["version"];
        $secret_key  = @$_POST["secret_key"];



        if (
            !verify_codename($codename)
            ||
            !verify_version($version)
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
            handle_post_with_params($link, $data, $vendor_id, $codename, $owner_email, $name, $version, $secret_key);

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
