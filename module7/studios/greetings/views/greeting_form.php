<h1>Build Your Greeting</h1>
<form action="greet.php" method="POST"/>
    <label>Your name:</label>
    <input type="text" name="recipient_name" />
    <br/>
    <label>Select a greeting:</label>
    <select name="select_greeting">
        <?php
            foreach ($data as $array => $index)
            {
                print("<option value=\"" . $index['text'] . "\">" . $index['text'] . "</option>");
            }
        ?>
    </select>
    <label>Or create your own:</label>
    <input type="text" name="custom_greeting" />
    <br/>
    <input type="submit"/>
</form>
