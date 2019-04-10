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
            break;
        }
    }



    function include_files_for_app_version($link, &$data, $app_version_id, $include_files)
    {
        if ($include_files)
        {
            $sql = "SELECT"
                . "     filename,"
                . "     download_name,"
                . "     hash"
                . " FROM " . DB_TABLE_APP_FILES
                . " WHERE app_version_id = '" . $link->real_escape_string($app_version_id) . "'"
                . " ORDER BY filename";



            $result = $link->query($sql);
            die_if_sql_failed($result, $link, $data, $sql);



            $files = [];

            while ($row = $result->fetch_assoc())
            {
                array_push($files, $row);
            }

            $result->close();



            $data["files"] = $files;
        }
    }



    function handle_get_for_app_version_id($link, &$data, $app_version_id, $include_files)
    {
        $sql = "SELECT"
            . "     id,"
            . "     version,"
            . "     hash"
            . " FROM " . DB_TABLE_APP_VERSIONS
            . " WHERE id        = '" . $link->real_escape_string($app_version_id) . "'"
            . "   AND completed = '1'";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        if ($result->num_rows == 0)
        {
            $result->close();



            db_disconnect($link);

            $data["message"] = "Version not found";

            die(json_encode($data));
        }



        $data["version"]            = $result->fetch_assoc();
        $data["version"]["id"]      = (int)$data["version"]["id"];
        $data["version"]["version"] = (int)$data["version"]["version"];

        $result->close();



        include_files_for_app_version($link, $data, $app_version_id, $include_files);
    }



    function handle_get_for_app_id_and_latest_version($link, &$data, $app_id, $include_files)
    {
        $sql = "SELECT"
            . "     id,"
            . "     version,"
            . "     hash"
            . " FROM " . DB_TABLE_APP_VERSIONS
            . " WHERE app_id    = '" . $link->real_escape_string($app_id) . "'"
            . "   AND completed = '1'"
            . " ORDER BY version DESC"
            . " LIMIT 1";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        if ($result->num_rows == 0)
        {
            $result->close();



            db_disconnect($link);

            $data["message"] = "Version not found";

            die(json_encode($data));
        }



        $data["version"]            = $result->fetch_assoc();
        $data["version"]["id"]      = (int)$data["version"]["id"];
        $data["version"]["version"] = (int)$data["version"]["version"];

        $result->close();



        include_files_for_app_version($link, $data, $data["version"]["id"], $include_files);
    }



    function handle_get_for_app_id_and_version($link, &$data, $app_id, $version, $include_files)
    {
        $sql = "";

        if (verify_version($version))
        {
            $sql = "SELECT"
                . "     id,"
                . "     version,"
                . "     hash"
                . " FROM " . DB_TABLE_APP_VERSIONS
                . " WHERE app_id    = '" . $link->real_escape_string($app_id) . "'"
                . "   AND version   = '" . $link->real_escape_string($version) . "'"
                . "   AND completed = '1'";
        }
        else
        {
            $sql = "SELECT"
                . "     id,"
                . "     version,"
                . "     hash"
                . " FROM " . DB_TABLE_APP_VERSIONS
                . " WHERE app_id    =  '" . $link->real_escape_string($app_id) . "'"
                . "   AND version   >= '" . $link->real_escape_string($version * 1000000) . "'"
                . "   AND version   <  '" . $link->real_escape_string(($version + 1) * 1000000) . "'"
                . "   AND completed =  '1'"
                . " ORDER BY version DESC"
                . " LIMIT 1";
        }



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        if ($result->num_rows == 0)
        {
            $result->close();



            db_disconnect($link);

            $data["message"] = "Version not found";

            die(json_encode($data));
        }



        $data["version"]            = $result->fetch_assoc();
        $data["version"]["id"]      = (int)$data["version"]["id"];
        $data["version"]["version"] = (int)$data["version"]["version"];

        $result->close();



        include_files_for_app_version($link, $data, $data["version"]["id"], $include_files);
    }



    function handle_get_for_app_id($link, &$data, $app_id)
    {
        $sql = "SELECT"
            . "     id,"
            . "     version,"
            . "     hash"
            . " FROM " . DB_TABLE_APP_VERSIONS
            . " WHERE app_id    = '" . $link->real_escape_string($app_id) . "'"
            . "   AND completed = '1'"
            . " ORDER BY version";



        $result = $link->query($sql);
        die_if_sql_failed($result, $link, $data, $sql);



        $versions = [];

        while ($row = $result->fetch_assoc())
        {
            $version            = $row;
            $version["id"]      = (int)$version["id"];
            $version["version"] = (int)$version["version"];

            array_push($versions, $version);
        }

        $result->close();



        $data["versions"] = $versions;
    }



    function handle_get()
    {
        header("Content-type: application/json");

        $data = [
            "status" => "Failed"
        ];



        $app_version_id = @$_GET["id"];
        $app_id         = @$_GET["app_id"];
        $codename       = @$_GET["codename"];
        $version        = @$_GET["version"];
        $include_files  = @$_GET["include_files"];



        if (isset($include_files))
        {
            $include_files = ($include_files == "true");
        }
        else
        {
            $include_files = true;
        }



        $link = db_connect();

        if ($link)
        {
            if (isset($app_version_id))
            {
                $app_version_id = (int)$app_version_id;

                if (!verify_app_version_id($app_version_id))
                {
                    db_disconnect($link);

                    $data["message"] = "Invalid parameters";

                    die(json_encode($data));
                }



                handle_get_for_app_version_id($link, $data, $app_version_id, $include_files);
            }
            else
            if (isset($app_id))
            {
                $app_id = (int)$app_id;

                if (!verify_app_id($app_id))
                {
                    db_disconnect($link);

                    $data["message"] = "Invalid parameters";

                    die(json_encode($data));
                }



                if (isset($version))
                {
                    if ($version == "latest")
                    {
                        handle_get_for_app_id_and_latest_version($link, $data, $app_id, $include_files);
                    }
                    else
                    {
                        $version = (int)$version;

                        if (
                            !verify_version_for_user($version)
                            &&
                            !verify_version($version)
                           )
                        {
                            db_disconnect($link);

                            $data["message"] = "Invalid parameters";

                            die(json_encode($data));
                        }



                        handle_get_for_app_id_and_version($link, $data, $app_id, $version, $include_files);
                    }
                }
                else
                {
                    handle_get_for_app_id($link, $data, $app_id);
                }
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



                $app_id = get_app_id_for_codename($link, $data, $codename);



                if (isset($version))
                {
                    if ($version == "latest")
                    {
                        handle_get_for_app_id_and_latest_version($link, $data, $app_id, $include_files);
                    }
                    else
                    {
                        $version = (int)$version;

                        if (
                            !verify_version_for_user($version)
                            &&
                            !verify_version($version)
                           )
                        {
                            db_disconnect($link);

                            $data["message"] = "Invalid parameters";

                            die(json_encode($data));
                        }



                        handle_get_for_app_id_and_version($link, $data, $app_id, $version, $include_files);
                    }
                }
                else
                {
                    handle_get_for_app_id($link, $data, $app_id);
                }
            }
            else
            {
                $data["message"] = "Invalid parameters";

                die(json_encode($data));
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
