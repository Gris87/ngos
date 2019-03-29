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
        header("Content-type: application/json");
        
        $data =
        [
            "status" => "OK"
        ];
        
        echo json_encode($data);
    }

    

    function handle_post_with_params($link, $data, $my_address, $my_secret_key, $your_secret_key)
    {
        validate_server($link, $data, $my_address, $my_secret_key);
        validate_this_server($link, $data, $your_secret_key);
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
        
        if (
            !isset($my_address)
            ||
            !isset($my_secret_key)
            ||
            !isset($your_secret_key)
            ||
            !is_string($my_address)
            ||
            !is_string($my_secret_key)
            ||
            !is_string($your_secret_key)
            ||
            $my_address == ""
            ||
            strlen($my_secret_key) != 1000
            ||
            strlen($your_secret_key) != 1000
           )
        {
            $data["message"] = "Invalid parameters";
            
            die(json_encode($data));
        }
        
        
        
        $link = db_connect();
        
        if ($link)
        {
            handle_post_with_params($link, $data, $my_address, $my_secret_key, $your_secret_key);
            
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
