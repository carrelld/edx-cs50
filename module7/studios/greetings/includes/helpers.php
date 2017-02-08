<?php

// include the CS50 library
require("../vendor/library50-php-5/CS50/CS50.php");

// initialize connection to the database
CS50::init(__DIR__ . "/../config.json");


function render($template, $data=[])
{
    $path = "../views/" . $template;
    
    // if the file exists, then extract $data and require the template
    if (file_exists($path))
    {
        extract($data);
        require($path);
    }
}


function create_new_greeting($new_greeting)
{
    // TODO
    // insert $new_greeting into the database, but only if we don't already have an entry with the same text
}


?>