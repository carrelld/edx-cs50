<?php

    // configuration
    require("../includes/config.php"); 

    // render portfolio
    $portfolio = CS50::query("SELECT symbol, shares FROM portfolio WHERE user_id = ? ORDER BY shares DESC", $_SESSION["id"]);
    foreach ($portfolio as &$row)
    {
        $lookup = lookup($row["symbol"]);
        if (!$lookup)
        {
            apologize("DATABASE ERROR: quote symbol in database does not exist, remove symbol from portfolio database table");
        }
        $row["total"] = number_format($lookup["price"] * $row["shares"], 2);
        $row["price"] = number_format($lookup["price"], 2);
        $row["name"] = $lookup["name"];
    }
    
    $userCash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    $cash = [
        "symbol" => "CASH",
        "total" => number_format($userCash[0]["cash"], 2),
        "name" => "",
        "price" => "",
        "shares" => ""
    ];
    array_unshift($portfolio, $cash);
    
    render("portfolio.php", ["title" => "Portfolio", "positions" => $portfolio, "cash" => $cash]);

?>
