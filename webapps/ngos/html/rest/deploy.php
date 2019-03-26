<?php
    require_once "../common/functions.php";



    define("CODENAME_REGEXP", "/^[a-z][a-z0-9_]*(\\.[a-z][a-z0-9_]*){2,}$/");



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
        // Nothing
    }



    function obtain_next_app_id($link, $data)
    {
        $res = 1;



        $sql = "SELECT"
            . "     value"
            . " FROM " . $GLOBALS["DB_TABLE_PROPERTIES"]
            . " WHERE name='last_app_id'";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        if ($result->num_rows == 0)
        {
            $sql = "INSERT INTO " . $GLOBALS["DB_TABLE_PROPERTIES"]
                . " (name, value)"
                . " VALUES("
                . "  'last_app_id',"
                . "  '1'"
                . ")";



            $result2 = $link->query($sql);
            die_if_sql_failed($result2, $link, $data, $sql);
        }
        else
        {
            $res = (int)$result->fetch_row()[0] + 1;



            $sql = "UPDATE " . $GLOBALS["DB_TABLE_PROPERTIES"]
                . " SET value='" . $res . "'"
                . " WHERE name='last_app_id'";



            $result2 = $link->query($sql);
            die_if_sql_failed($result2, $link, $data, $sql);
        }



        $result->close();



        return $res;
    }



    function handle_post_with_params($link, $data, $app_id, $codename, $name, $version, $content)
    {
        $link->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);



        $sql = "SELECT"
            . "     id"
            . " FROM " . $GLOBALS["DB_TABLE_APPS"]
            . " WHERE codename='" . $link->real_escape_string($codename) . "'";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        if ($result->num_rows == 0)
        {
            if (!isset($app_id))
            {
                $app_id = obtain_next_app_id($link, $data);
            }



            $sql = "INSERT INTO " . $GLOBALS["DB_TABLE_APPS"]
                . " (id, codename, name)"
                . " VALUES("
                . "  '" . $link->real_escape_string($app_id) . "',"
                . "  '" . $link->real_escape_string($codename) . "',"
                . "  '" . $link->real_escape_string($name) . "'"
                . ")";



            $result2 = $link->query($sql);
            die_if_sql_failed($result2, $link, $data, $sql);
        }
        else
        {
            $app_id = $result->fetch_row()[0];
        }

        $result->close();



        $link->commit();
    }



    function handle_post()
    {
        header("Content-type: application/json");

        $data =
        [
            "status" => "Failed"
        ];



        $_POST = json_decode(file_get_contents('php://input'), true);



        $app_id   = @$_POST["app_id"];
        $codename = @$_POST["codename"];
        $name     = @$_POST["name"];
        $version  = @$_POST["version"];
        $content  = @$_POST["content"];

        if (
            !isset($codename)
            ||
            !isset($name)
            ||
            !isset($content)
            ||
            !is_string($codename)
            ||
            !preg_match(constant("CODENAME_REGEXP"), $codename)
           )
        {
            $data["message"] = "Invalid parameters";

            die(json_encode($data));
        }



        $link = db_connect();

        if ($link)
        {
            handle_post_with_params($link, $data, $app_id, $codename, $name, $version, $content);

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
