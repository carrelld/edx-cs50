<div>
    <h1>Your Stock Portfolio</h1>
    <br/>
    <table class="table table-striped table-hover" style="text-align:left">
        <thead>    
            <tr>
                <th>
                    Symbol
                </th>
                <th>
                    Name
                </th>
                <th>
                    Shares
                </th>
                <th>
                    Price
                </th>
                <th>
                    TOTAL
                </th>
            </tr>
        </thead>
        <tbody>
            <?php
                foreach ($positions as $row)
                {
                    print("<tr>");
                    print("<td>" . $row["symbol"] . "</td>");
                    print("<td>" . $row["name"] . "</td>");
                    print("<td>" . $row["shares"] . "</td>");
                    print("<td>" . $row["price"] . "</td>");
                    print("<td>" . $row["total"] . "</td>");
                    print("</tr>");
                }
            ?>
        </tbody>
    </table>
</div>
