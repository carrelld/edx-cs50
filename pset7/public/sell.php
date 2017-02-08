<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // Make sure they have stock to sell
        $userStocks = CS50::query("SELECT symbol FROM portfolio WHERE user_id = ?", $_SESSION["id"]);
        if (!$userStocks)
        {
            apologize("You don't have anything to sell!");
        }
        // else render form
        render("sell_form.php", ["title" => "Sell", "userStocks" => $userStocks]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate against empty fields
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide the stock symbol you want to sell.");
        }
        if (empty($_POST["shares"]))
        {
            apologize("You must provide how many shares you want to sell.");
        }
        
        // validate other requirements
        extract($_POST);
        $symbol = strtoupper($symbol);
        // get current quantity and price, validate symbol
        $portfolioQuantity = CS50::query("SELECT shares FROM portfolio WHERE user_id = ? and symbol = ?", $_SESSION["id"], $symbol);
        $quotePrice = lookup($symbol);
        if (!$portfolioQuantity || !$quotePrice)
        {
            apologize("Error retrieving " . $symbol . " from the database");
        }
        $portfolioQuantity = $portfolioQuantity[0]["shares"];
        $quotePrice = $quotePrice["price"];
        
        if ($shares > $portfolioQuantity)
        {
            apologize("You can't sell more shares than you have.");
        }
        $sharesIsInt = preg_match("/^\d+$/", $shares);
        if ($shares < 1 || !$sharesIsInt)
        {
            apologize("Please enter the number of shares you wish to sell (whole number greater than 0).");
        }
        
        // update database
        if ($shares == $portfolioQuantity)
        {
            CS50::query("DELETE FROM portfolio WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $symbol);
        }
        else
        {
            CS50::query("UPDATE portfolio SET shares = shares - ? WHERE user_id = ? AND symbol = ?", $shares, $_SESSION["id"], $symbol);
        }
        $cashFromSale = $shares * $quotePrice;
        CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $cashFromSale, $_SESSION["id"]);
        
        // update transactions table
        CS50::query("INSERT INTO transactions (type, user_id, symbol, shares, price) VALUES ('SELL', ?, ?, ?, ?)", $_SESSION["id"], $symbol, $shares, $quotePrice);
        
        redirect("/");
        
        // else apologize
        apologize("Error processing the sale");
    }

?>
