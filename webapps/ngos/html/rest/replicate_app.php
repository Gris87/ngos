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



    function handle_post_with_params($link, $data, $my_address, $my_secret_key, $your_secret_key, $app_id, $vendor_id, $codename, $owner_email, $name, $secret_key)
    {
        validate_access($link, $data, $my_address, $my_secret_key, $your_secret_key);
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
        $app_id          = @$_POST["app_id"];
        $vendor_id       = @$_POST["vendor_id"];
        $codename        = @$_POST["codename"];
        $owner_email     = @$_POST["owner_email"];
        $name            = @$_POST["name"];
        $secret_key      = @$_POST["secret_key"];

        
        
        if (
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
            handle_post_with_params($link, $data, $my_address, $my_secret_key, $your_secret_key, $app_id, $vendor_id, $codename, $owner_email, $name, $secret_key);

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
