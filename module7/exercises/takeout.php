<?php
    
    $userCount = readline("How many people are you ordering for? ");
    $orders = [];
    for ($counter = 0; $counter < $userCount; $counter++)
    {
        $name = readline("Order $counter : What's your name? ");
        $order = readline("Order $counter : What would you like to eat? ");
        $orders[$name] = $order;
    }
    
    foreach ($orders as $name => $order)
    {
        print("$name:\t$order\n");
    }
    
    
?>