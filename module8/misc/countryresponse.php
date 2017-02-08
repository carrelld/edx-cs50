<?php

session_start();

$countries = ["USA" => "Washington, D.C.", "Canada" => "Ottawa", "Mexico" => "Mexico City"];

$country = $_POST["country"];
if($country == "None" || empty($_POST["country"]))
{
    print("Please <a href='country-form.php'>go back</a> and pick a country.");
}
else
{
    print("The capital of {$country} is {$countries[$country]}.<br /><br />");
    
    if(isset($_SESSION["visited2"]))
    {
        $visited = $_SESSION["visited2"];
    }
    else
    {
        $visited = [];
    }
    
    array_push($visited, $country);
    
    print("Here are the countries you've selected so far: <br /><br />");
    foreach($visited as $visitedCountry)
    {
        print($visitedCountry);
        print("<br />");
    }
    
    $_SESSION["visited2"] = $visited;
}

?>