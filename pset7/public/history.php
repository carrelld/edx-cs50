<?php

    // configuration
    require("../includes/config.php"); 

    // render history
    $transactions = CS50::query("SELECT * FROM transactions WHERE user_id = ? ORDER BY time ASC", $_SESSION["id"]);
    
    // format price for each stock
    foreach ($transactions as &$row)
    {
        $row["price"] = number_format($row["price"], 2);
    }
    
    render("history.php", ["title" => "History", "transactions" => $transactions]);

?>
