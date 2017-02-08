<?php

    // configuration
    require("../includes/config.php"); 
    
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php", ["title" => "Lookup Stock Quote"]);
    }
    
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        extract($_POST);
        
        // get price of symbol provided
        $quote = lookup($symbol);
        if (!$quote)
        {
            apologize("\"{$symbol}\" is not a valid stock symbol");
        }
        
        $title = "Quote -- {$quote['symbol']}";
        
        render("quote_display.php", ["title" => $title, "quote" => $quote]);
    }

?>