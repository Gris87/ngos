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



    function handle_post()
    {
        // Nothing
    }
?>
