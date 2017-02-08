<?php

// TODO start a session
    session_start();

// TODO if the user provided a "username" field, set the session's "username" key to the value they provided
    if (!empty($_GET["username"]))
    {
        $_SESSION["username"] = $_GET["username"];
    }

// TODO if the session still does not have a value for the "username" key, then redirect the user back to the form
    elseif (!isset($_SESSION["username"]))
    {
        header("Location: ./hello-form.php");
    }
?>

<!DOCTYPE html>
<head>
</head>
<body>
    Last time I checked, your name is <?= $_SESSION["username"] ?>
</body>