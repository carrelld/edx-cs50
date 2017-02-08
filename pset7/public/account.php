<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("account.php", ["title" => "My Account"]);
    }

    // check if changepassword form submitted
    else if ($_SERVER["REQUEST_METHOD"] == "POST" && $_POST["form"] == "changepassword")
    {
        extract($_POST);
        
        if (empty($password) || empty($confirmation))
        {
            apologize("Please fill in both the password and the confirmation.");
        }
        
        if ($password != $confirmation)
        {
            apologize("Your passwords don't match!");
        }
        
        // Change pass in database
        $changePass = CS50::query("UPDATE users SET hash = ? WHERE id = ?", password_hash($_POST["password"], PASSWORD_DEFAULT), $_SESSION["id"]);
        if (!$changePass) {
            apologize("That username is taken or user can't be added for some other reason");
        }
        
        redirect("/account.php");
        
        // else apologize
        apologize("Change Password Form Submission Error");
    }
    
    // Check if addfunds form submitted
    else if ($_SERVER["REQUEST_METHOD"] == "POST" && $_POST["form"] == "addfunds")
    {
        extract($_POST);
        
        // validate
        if (empty($amount))
        {
            apologize("Please fill in the amount of money you wish to add.");
        }
        
        if ($amount <= 0)
        {
            apologize("Please use a positive number");
        }
        
        // update database
        CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $amount, $_SESSION["id"]);
        
        redirect("/account.php");
        
        // else apologize
        apologize("Add Funds Form Submission Error");
    }

?>