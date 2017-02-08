<div>
    <p>
        <?php
            print($quote["symbol"] . "\t|\t");
            print($quote["name"] . "\t|\t");
            print("$" . number_format($quote["price"], 2));
            print("<br/>");
        ?>
    </p>
</div>