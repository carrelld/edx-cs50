<?php

require("../includes/helpers.php");


// for debugging, uncomment the line below so you can see what you're working with in $_POST
// var_dump($_POST);


// extract the $_POST dictionary into local variables (e.g. $recipient_name, $select_greeting, etc)
extract($_POST);

//DEBUGGING
//print("This is POST");
//var_dump($_POST);


// VALIDATION ----------------------------------------------

// if the user didn't type their name, redirect back to the form
if (empty($recipient_name))
{
    header("Location: index.php");
}



// DETERMINE GREETING TEXT -------------------------------

// decide what the greeting text (e.g. "What is up") should be. 
// by default, use whatever was chosen from the <select> menu
$greeting_text = $select_greeting;

// TODO 
// if the user provided a custom greeting,
//  -- overwrite $greeting_text to be the custom greeting instead
//  -- and also add the custom greeting as a new row to the database 
//          -- to do this, simply pass it to the create_new_greeting() function from helpers.php


if (!empty($custom_greeting))
{
    $greeting_text = $custom_greeting;
    $insert_return = CS50::query("INSERT INTO greetings (text, num_times) VALUES (?,?)", $greeting_text, 0);
    if (!$insert_return)
    {
        print("Key {$insert_return} failed insertion into the table </BR>");
    }
}



// UPDATE `num_times` ---------------------------------------

// TODO
// increment the `num_times` field in this greeting and update the database. 3 steps:

// 1. get this greeting (the one whose `text` value matches $greeting_text) from the database
$this_greeting = CS50::query("SELECT * FROM greetings WHERE text = ? LIMIT 1", $greeting_text); 
$this_greeting = $this_greeting[0]; //Any other way to get at the "Lower level" array since the top level only has one array?
print("This is this_greeting {$this_greeting['id']} {$this_greeting['text']} {$this_greeting['num_times']}");
var_dump($this_greeting);

// 2. figure out what the new `num_times` value should be, and store it in the local variable below
$new_num_times = $this_greeting['num_times'] + 1;

// 3. update the database so that this greeting entry has the correct `num_times` value
CS50::query("UPDATE greetings SET num_times = ? WHERE id = ?", $new_num_times, $this_greeting['id']);

    // DEBUGGING
    //$temp = CS50::query("SELECT * FROM greetings");
    //var_dump($temp);



// RENDER STUFF -------------------------------------------

render("header.php", ["title" => $greeting_text]);

$data = [
    "num_times" => $new_num_times, 
    "greeting_text" => $greeting_text,
    "recipient_name" => $recipient_name
    // what else do we need to pass over to greeting_display.php?
];
render("greeting_display.php", $data);

render("footer.php");

?>
