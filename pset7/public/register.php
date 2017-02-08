<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["username"]))
        {
            apologize("You must provide your username.");
        }
        else if (empty($_POST["password"]))
        {
            apologize("You must provide your password.");
        }
        else if (empty($_POST["confirmation"]))
        {
            apologize("You must provide your password confirmation.");
        }
        else if ($_POST["password"] != $_POST["confirmation"])
        {
            apologize("Your passwords don't match!");
        }
        
        // Add user to table 'users'
        $addedUserBool = CS50::query("INSERT IGNORE INTO users (username, hash, cash) VALUES(?, ?, 10000.0000)", $_POST["username"], password_hash($_POST["password"], PASSWORD_DEFAULT));
        if (!$addedUserBool) {
            apologize("That username is taken or user can't be added for some other reason");
        }
        // Log-in new user
        $addedUserID = CS50::query("SELECT LAST_INSERT_ID() AS id");
        $addedUserID = $addedUserID[0]["id"];
        $_SESSION["id"] = $addedUserID;
        $username = CS50::query("SELECT username FROM users WHERE id = ?", $_SESSION["id"]);
        $username = $username[0]["username"];
        $_SESSION["username"] = $username;
        
        redirect("/");
        
        // Otherwise appologize
        apologize("You should never have seen this...");
    }

?>