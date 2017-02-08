<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy_form.php", ["title" => "Buy"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate against empty fields
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide the stock symbol you want to buy.");
        }
        if (empty($_POST["shares"]))
        {
            apologize("You must provide how many shares you want to buy.");
        }
        
        // validate other requirements
        extract($_POST);
        $symbol = strtoupper($symbol);
        // get current quantity and price, validate symbol
        $userCash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        $quotePrice = lookup($symbol);
        if (!$quotePrice)
        {
            apologize("Error retrieving " . $symbol . " from the database");
        }
        $userCash = $userCash[0]["cash"];
        $quotePrice = $quotePrice["price"];
        $sharesIsInt = preg_match("/^\d+$/", $shares);
        $cashFromBuy = $shares * $quotePrice;
        $enoughMoney = $cashFromBuy <= $userCash;
        
        if (!$sharesIsInt || $shares < 1)
        {
            apologize("Please use a whole number of shares greater than 0.");
        }
        if (!$enoughMoney)
        {
            apologize("You don't have enough money.");
        }
        
        // update database
        $userSymbolExists = CS50::query("SELECT id FROM portfolio WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $symbol);
        if (!$userSymbolExists)
        {
            CS50::query("INSERT INTO portfolio (user_id, symbol, shares) VALUES (?, ?, ?)", $_SESSION["id"], $symbol, $shares);
        }
        else
        {
            CS50::query("UPDATE portfolio SET shares = shares + ? WHERE user_id = ? AND symbol = ?", $shares, $_SESSION["id"], $symbol);
        }
        
        CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $cashFromBuy, $_SESSION["id"]);
        
        // update transactions table
        CS50::query("INSERT INTO transactions (type, user_id, symbol, shares, price) VALUES ('BUY', ?, ?, ?, ?)", $_SESSION["id"], $symbol, $shares, $quotePrice);
        
        redirect("/");
        
        // else apologize
        apologize("Error processing the sale");
    }

?>
