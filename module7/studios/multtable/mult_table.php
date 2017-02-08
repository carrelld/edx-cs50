<?php

    $h = $_POST["height"];
    $w = $_POST["width"];
    
    // if we don't have a number, redirect back to the form page
    if (empty($h) || empty($w)) {
        header("Location: ./mult_form.php");
        exit;
    }
    
?>

<!DOCTYPE html>
<html>
    <head>
        <title>Your Table is Ready</title>
        <style type="text/css">
            
            .center
            {
                margin-left:auto;
                margin-right:auto;
                width:50%;
                height:500%;
                border-style: solid;
                border-width: 5px;
                border-color: black;
            }
            
            td
            {
                background-color:yellow;
                text-align:center;
            }
            
        </style>
    </head>
    <body>
        <div class="center">
            <table class="center">
                <?php for ($i = 1; $i <= $h; $i++): ?>
                    <tr>
                        <?php for ($j = 1; $j <= $w; $j++): ?>
                            <td><?php print($i * $j) ?></td>
                        <?php endfor ?>
                    </tr>
                <?php endfor ?>
            </table>
        </div>
    </body>
</html>