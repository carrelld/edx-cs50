<?php 

$username = $_GET["username"]; 
$greeting = $_GET["greeting"]; 

?>

<!DOCTYPE html>
<head>
</head>
<body>
    <!-- TODO replace "false" below with a condition to check if either value is empty (same condition as last time) -->
    <?php if(empty($username) || empty($greeting)): ?> 
        <!-- TODO Yell at the user and provide a link back to the form -->
        You forgot either a username or greeting! Go <a href="./hello-form.php">BACK</a> and fix it!
    <?php else: ?>
        <!-- TODO greet the user just like last time -->
        <?php print("{$greeting}, {$username}!"); ?>
    <?php endif ?>
</body>