<!DOCTYPE html>
<html>
    <head>
        <title>Hello 0</title>
    </head>
    <body>
        <form action="hello-response.php" method="GET">
            <label>Say</label>
            <select name="greeting">
                <option value="hello">hello</option>
                <option value="hola">hola</option>
                <option value="Hiya">Hiya</option>
                <option value="YoYOYO">YoYOYO</option>
            </select>
            <label>to</label>
            <input type="text" name="username"/>
            <input type="submit" value="Submit"/>
        </form>
    </body>
</html>