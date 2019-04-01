<?php
    require_once "../common/functions.php";



    define("CODENAME_REGEXP", "/^[a-z][a-z0-9_]*(\\.[a-z][a-z0-9_]*){2,}$/");



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



    function obtain_next_app_id($link, $data)
    {
        $res = 1;

        
        
        $link->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);

        

        $sql = "SELECT"
            . "     value"
            . " FROM " . $GLOBALS["DB_TABLE_PROPERTIES"]
            . " WHERE name='last_app_id'";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        if ($result->num_rows == 1)
        {
            $res = (int)$result->fetch_row()[0] + 1;
            $result->close();



            $sql = "UPDATE " . $GLOBALS["DB_TABLE_PROPERTIES"]
                . " SET value='" . $link->real_escape_string($res) . "'"
                . " WHERE name='last_app_id'";



            $result2 = $link->query($sql);
            die_if_sql_failed($result2, $link, $data, $sql);
            
            
            
            $link->commit();
        }
        else
        {
            $result->close();
            $link->commit();



            $error_details = "Access violation";
            error_log($error_details);

            db_disconnect($link);

            $data["message"] = "Access error";
            $data["details"] = $error_details;

            die(json_encode($data));
        }
        
        

        return $res;
    }
    
    
    
    function get_or_create_app_id($link, $data, $vendor_id, $codename, $owner_email, $name, $secret_key)
    {
        $res = 0;
        
        
        
        $sql = "SELECT"
            . "     id,"
            . "     secret_key"
            . " FROM " . $GLOBALS["DB_TABLE_APPS"]
            . " WHERE codename='" . $link->real_escape_string($codename) . "'";
                    
                    
                    
        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);
                    
                    
        
        if ($result->num_rows == 0)
        {
            $result->close();
            
            
            
            if (
                !isset($vendor_id)
                ||
                !isset($owner_email)
                ||
                !isset($name)
                ||
                !is_int($vendor_id)
                ||
                !is_string($owner_email)
                ||
                !is_string($name)
                ||
                $vendor_id <= 0
                ||
                $owner_email == ""
                ||
                $name == ""
                )
            {
                db_disconnect($link);
                
                $data["message"] = "Invalid parameters";
                
                die(json_encode($data));
            }
            
            
            
            $res = obtain_next_app_id($link, $data);
            
            
            
            $sql = "INSERT INTO " . $GLOBALS["DB_TABLE_APPS"]
                . " (id, vendor_id, codename, owner_email, name, description, secret_key)"
                . " VALUES("
                . "  '" . $link->real_escape_string($res)      . "',"
                . "  '" . $link->real_escape_string($vendor_id)   . "',"
                . "  '" . $link->real_escape_string($codename)    . "',"
                . "  '" . $link->real_escape_string($owner_email) . "',"
                . "  '" . $link->real_escape_string($name)        . "',"
                . "  '',"
                . "  '" . $link->real_escape_string($secret_key)  . "'"
                . ")";
                                                
                                                
                                                
                $result2 = $link->query($sql);
                die_if_sql_failed($result2, $link, $data, $sql);
        }
        else
        {
            $row = $result->fetch_array();
            
            $res         = $row["id"];
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



    function handle_post_for_add_version($link, &$data, $vendor_id, $codename, $owner_email, $name, $version, $secret_key)
    {
        $app_id = get_or_create_app_id($link, $data, $vendor_id, $codename, $owner_email, $name, $secret_key);



        $sql = "INSERT INTO " . $GLOBALS["DB_TABLE_APP_VERSIONS"]
            . " (app_id, version, hash, completed)"
            . " VALUES("
            . "  '" . $link->real_escape_string($app_id)  . "',"
            . "  '" . $link->real_escape_string($version) . "',"
            . "  '00000000000000000000000000000000',"
            . "  '0'"
            . ")";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);

        
        
        $app_version_id = $link->insert_id;

        

        $data["app_id"]         = $app_id;
        $data["app_version_id"] = $app_version_id;
    }
    
    
    
    function handle_post_with_params($link, &$data, $action, $vendor_id, $codename, $owner_email, $name, $version, $secret_key)
    {
        switch ($action)
        {
            case "add_version":
            {
                handle_post_for_add_version($link, $data, $vendor_id, $codename, $owner_email, $name, $version, $secret_key);
            }
            break;
                
            default:
            {
                db_disconnect($link);
                
                $data["message"] = "Invalid parameters";
                
                die(json_encode($data));
            }
        }
    }



    function handle_post()
    {
        header("Content-type: application/json");

        $data =
        [
            "status" => "Failed"
        ];



        $_POST = json_decode(file_get_contents('php://input'), true);



        $action      = @$_POST["action"];
        $vendor_id   = @$_POST["vendor_id"];
        $codename    = @$_POST["codename"];
        $owner_email = @$_POST["owner_email"];
        $name        = @$_POST["name"];
        $version     = @$_POST["version"];
        $secret_key  = @$_POST["secret_key"];



        if (
            !isset($action)
            ||
            !isset($codename)
            ||
            !isset($version)
            ||
            !isset($secret_key)
            ||
            !is_string($action)
            ||
            !is_string($codename)
            ||
            !is_int($version)
            ||
            !is_string($secret_key)
            ||
            $action == ""
            ||
            !preg_match(constant("CODENAME_REGEXP"), $codename)
            ||
            $version < 20190101000000
            ||
            strlen($secret_key) != 1000
           )
        {
            $data["message"] = "Invalid parameters";

            die(json_encode($data));
        }



        $link = db_connect();

        if ($link)
        {
            handle_post_with_params($link, $data, $action, $vendor_id, $codename, $owner_email, $name, $version, $secret_key);

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
