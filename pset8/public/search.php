<?php

    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];

    // TODO: search database for places matching $_GET["geo"], store in $places
    extract($_GET);
    
    if (is_numeric($geo))
    {
        // postal codes
        $places = CS50::query("SELECT * FROM places WHERE postal_code LIKE ?", $geo . "%");
    }
    else
    {
        // cities and states
        $places = CS50::query("SELECT * FROM places WHERE MATCH(place_name, admin_name1) AGAINST (?)", "%" . $geo . "%");
    }

    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));

?>