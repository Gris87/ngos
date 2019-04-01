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
        echo password_hash("Grisly-ly=Gris", PASSWORD_BCRYPT);
    }



    function handle_post()
    {
        // Nothing
    }
?>
