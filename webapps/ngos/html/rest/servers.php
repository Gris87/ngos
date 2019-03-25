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
            "status" => "Failed"
        ];



        $link = db_connect();

        if ($link)
        {
            $sql = "SELECT"
                . "     address"
                . " FROM " . $GLOBALS["DB_TABLE_SERVERS"];



            $result = $link->query($sql);
            die_if_sql_failed($result, $link, $data, $sql);



            $servers = [];

            while ($row = $result->fetch_row())
            {
                array_push($servers, $row[0]);
            }

            $result->close();



            $data["servers"] = $servers;



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



    function handle_post()
    {
        // Nothing
    }
?>
