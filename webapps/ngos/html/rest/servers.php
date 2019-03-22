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

            if (!$result)
            {
                $link_error = $link->error;
                error_log("SQL Failed: " . $sql . " Error: " . $link_error);

                db_disconnect($link);

                $data["message"] = "Database error";
                $data["details"] = $link_error;
                die(json_encode($data));
            }



            $servers = [];

            while ($row = $result->fetch_row())
            {
                array_push($servers, $row[0]);
            }



            $data["status"]  = "OK";
            $data["servers"] = $servers;

            echo json_encode($data);



            db_disconnect($link);
        }
        else
        {
            $data["message"] = "Database error";
            die(json_encode($data));
        }
    }



    function handle_post()
    {
        // Nothing
    }
?>
