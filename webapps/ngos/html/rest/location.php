<?php                                                                                                                                                                                                    // Colorize: green
    require_once "../common/functions.php";                                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    function handle_request()                                                                                                                                                                            // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        switch ($_SERVER["REQUEST_METHOD"])                                                                                                                                                              // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            case "GET":                                                                                                                                                                                  // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                handle_get();                                                                                                                                                                            // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            break;                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            case "POST":                                                                                                                                                                                 // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                handle_post();                                                                                                                                                                           // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            break;                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            default:                                                                                                                                                                                     // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                die("Unknown method");                                                                                                                                                                   // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            break;                                                                                                                                                                                       // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    function handle_get()                                                                                                                                                                                // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        // Nothing                                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    function handle_post_with_params($link, $data, $my_address, $my_secret_key, $your_secret_key, $region_id, $address)                                                                                  // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        validate_access($link, $data, $my_address, $my_secret_key, $your_secret_key);                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        $own_address = get_server_name($link, $data);                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if ($own_address == $address)                                                                                                                                                                    // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            set_region_id($link, $data, $region_id);                                                                                                                                                     // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            $own_secret_key = get_secret_key($link, $data);                                                                                                                                              // Colorize: green
            $secret_key     = get_server_secret_key($link, $data, $address);                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            validate_server_with_ping($link, $data, $own_address, $own_secret_key, $address, $secret_key);                                                                                               // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        $delay = get_delay_to_server($link, $data, $address);                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Ignore PhpAlignmentVerifier [BEGIN]                                                                                                                                                           // Colorize: green
        $sql = "UPDATE " . DB_TABLE_SERVERS                                                                                                                                                              // Colorize: green
            . " SET region_id = '" . $link->real_escape_string($region_id) . "',"                                                                                                                        // Colorize: green
            . "     delay     = '" . $link->real_escape_string($delay)     . "'"                                                                                                                         // Colorize: green
            . " WHERE address = '" . $link->real_escape_string($address)   . "'";                                                                                                                        // Colorize: green
        // Ignore PhpAlignmentVerifier [END]                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        $result = $link->query($sql);                                                                                                                                                                    // Colorize: green
        die_if_sql_failed($result, $link, $data, $sql);                                                                                                                                                  // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    function handle_post()                                                                                                                                                                               // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        header("Content-type: application/json");                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        $data =                                                                                                                                                                                          // Colorize: green
        [                                                                                                                                                                                                // Colorize: green
            "status" => "Failed"                                                                                                                                                                         // Colorize: green
        ];                                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        $_POST = json_decode(file_get_contents("php://input"), true);                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        $my_address      = @$_POST["my_address"];                                                                                                                                                        // Colorize: green
        $my_secret_key   = @$_POST["my_secret_key"];                                                                                                                                                     // Colorize: green
        $your_secret_key = @$_POST["your_secret_key"];                                                                                                                                                   // Colorize: green
        $region_id       = @$_POST["region_id"];                                                                                                                                                         // Colorize: green
        $address         = @$_POST["address"];                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (                                                                                                                                                                                             // Colorize: green
            !verify_address($my_address)                                                                                                                                                                 // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            !verify_secret_key($my_secret_key)                                                                                                                                                           // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            !verify_secret_key($your_secret_key)                                                                                                                                                         // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            !verify_region_id($region_id)                                                                                                                                                                // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            !verify_address($address)                                                                                                                                                                    // Colorize: green
           )                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            $data["message"] = "Invalid parameters";                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            die(json_encode($data));                                                                                                                                                                     // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        $link = db_connect();                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if ($link)                                                                                                                                                                                       // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            handle_post_with_params($link, $data, $my_address, $my_secret_key, $your_secret_key, $region_id, $address);                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            db_disconnect($link);                                                                                                                                                                        // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            $data["message"] = "Database connection error";                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            die(json_encode($data));                                                                                                                                                                     // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        $data["status"] = "OK";                                                                                                                                                                          // Colorize: green
        echo json_encode($data);                                                                                                                                                                         // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    handle_request();                                                                                                                                                                                    // Colorize: green
?>                                                                                                                                                                                                       // Colorize: green
