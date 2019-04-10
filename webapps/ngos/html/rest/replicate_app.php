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
            break;
        }
    }



    function handle_get()
    {
        // Nothing
    }



    function insert_app($link, $data, $app_id, $vendor_id, $codename, $owner_email, $name, $secret_key)
    {
        $sql = "SELECT"
            . "     secret_key"
            . " FROM " . DB_TABLE_APPS
            . " WHERE id = '" . $link->real_escape_string($app_id) . "'";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        if ($result->num_rows == 0)
        {
            $result->close();



            $sql = "INSERT INTO " . DB_TABLE_APPS
                . " (id, vendor_id, codename, owner_email, name, description, secret_key)"
                . " VALUES("
                . "  '" . $link->real_escape_string($app_id)      . "',"
                . "  '" . $link->real_escape_string($vendor_id)   . "',"
                . "  '" . $link->real_escape_string($codename)    . "',"
                . "  '" . $link->real_escape_string($owner_email) . "',"
                . "  '" . $link->real_escape_string($name)        . "',"
                . "  '',"
                . "  '" . $link->real_escape_string($secret_key)  . "'"
                . ")";



            $result = $link->query($sql);
            die_if_sql_failed($result, $link, $data, $sql);
        }
        else
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
    }



    function forward_message_to_another_servers($link, $data, $level, $my_address, $my_secret_key, $app_id, $vendor_id, $codename, $owner_email, $name, $secret_key)
    {
        switch ($level)
        {
            case 0:
            {
                $replicate_data = [
                    "my_address"    => $my_address,
                    "my_secret_key" => $my_secret_key,
                    "app_id"        => $app_id,
                    "vendor_id"     => $vendor_id,
                    "codename"      => $codename,
                    "owner_email"   => $owner_email,
                    "name"          => $name,
                    "secret_key"    => $secret_key
                ];

                $region_id = get_region_id($link, $data);



                replicate_by_region($link, $data, $replicate_data, "/rest/replicate_app.php", $region_id, $my_address);
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
            break;
        }
    }



    function handle_post_with_params($link, $data, $level, $my_address, $my_secret_key, $your_secret_key, $app_id, $vendor_id, $codename, $owner_email, $name, $secret_key)
    {
        validate_access($link, $data, $my_address, $my_secret_key, $your_secret_key);



        insert_app($link, $data, $app_id, $vendor_id, $codename, $owner_email, $name, $secret_key);



        $own_address = get_server_name($link, $data);

        forward_message_to_another_servers($link, $data, $level, $own_address, $your_secret_key, $app_id, $vendor_id, $codename, $owner_email, $name, $secret_key);
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
        $app_id          = @$_POST["app_id"];
        $vendor_id       = @$_POST["vendor_id"];
        $codename        = @$_POST["codename"];
        $owner_email     = @$_POST["owner_email"];
        $name            = @$_POST["name"];
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
            !verify_app_id($app_id)
            ||
            !verify_vendor_id($vendor_id)
            ||
            !verify_codename($codename)
            ||
            !verify_email($owner_email)
            ||
            !verify_name($name)
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
            handle_post_with_params($link, $data, $level, $my_address, $my_secret_key, $your_secret_key, $app_id, $vendor_id, $codename, $owner_email, $name, $secret_key);

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
