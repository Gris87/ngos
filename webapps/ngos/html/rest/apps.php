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



    function handle_get_for_app_id($link, &$data, $app_id)
    {
        $sql = "SELECT"
            . "     id,"
            . "     codename,"
            . "     name,"
            . "     description"
            . " FROM " . DB_TABLE_APPS
            . " WHERE id = '" . $link->real_escape_string($app_id) . "'";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        if ($result->num_rows == 0)
        {
            $result->close();



            db_disconnect($link);

            $data["message"] = "Application not found";

            die(json_encode($data));
        }



        $data["app"]       = $result->fetch_assoc();
        $data["app"]["id"] = (int)$data["app"]["id"];

        $result->close();
    }



    function handle_get_for_codename($link, &$data, $codename)
    {
        $sql = "SELECT"
            . "     id,"
            . "     codename,"
            . "     name,"
            . "     description"
            . " FROM " . DB_TABLE_APPS
            . " WHERE codename = '" . $link->real_escape_string($codename) . "'";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        if ($result->num_rows == 0)
        {
            $result->close();



            db_disconnect($link);

            $data["message"] = "Application not found";

            die(json_encode($data));
        }



        $data["app"]       = $result->fetch_assoc();
        $data["app"]["id"] = (int)$data["app"]["id"];

        $result->close();
    }



    function handle_get_for_apps($link, &$data)
    {
        $sql = "SELECT"
            . "     id,"
            . "     codename,"
            . "     name,"
            . "     description"
            . " FROM " . DB_TABLE_APPS;



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        $apps = [];

        while ($row = $result->fetch_assoc())
        {
            $app       = $row;
            $app["id"] = (int)$app["id"];

            array_push($apps, $app);
        }

        $result->close();



        $data["apps"] = $apps;
    }



    function handle_get()
    {
        header("Content-type: application/json");

        $data = [
            "status" => "Failed"
        ];



        $app_id   = @$_GET["id"];
        $codename = @$_GET["codename"];



        $link = db_connect();

        if ($link)
        {
            if (isset($app_id))
            {
                $app_id = (int)$app_id;

                if (!verify_app_id($app_id))
                {
                    db_disconnect($link);

                    $data["message"] = "Invalid parameters";

                    die(json_encode($data));
                }



                handle_get_for_app_id($link, $data, $app_id);
            }
            else
            if (isset($codename))
            {
                if (!verify_codename($codename))
                {
                    db_disconnect($link);

                    $data["message"] = "Invalid parameters";

                    die(json_encode($data));
                }



                handle_get_for_codename($link, $data, $codename);
            }
            else
            {
                handle_get_for_apps($link, $data);
            }



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



    handle_request();
?>
