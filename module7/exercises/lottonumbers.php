<?php

    $lottoNumbers = [123, 555, 23, 7129];
    $drawnNumbers = [
        "Sally" => 23,
        "Ken" => 3,
        "Jeremy" => 8,
        "Rhonda" => 7129
    ];
    
    print "Tonight's numbers: ";
    
    // TODO: your code goes here!
    // loop through
    foreach ($lottoNumbers as $numbers)
    {
        print("$numbers, ");
    }
    print("\n\n");
    
    print "\nParticipant's drawn numbers:\n";
    
    // TODO: your code goes here:
    // loop through the drawn numbers printing each name and number
    foreach ($drawnNumbers as $key => $number)
    {
        print("$key: $number\n");
    }
    
?>