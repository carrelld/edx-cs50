<div>
    <h1>Your Transaction History</h1>
    <br/>
    <table class="table table-striped table-hover" style="text-align:left">
        <thead>    
            <tr>
                <th>
                    Transaction
                </th>
                <th>
                    Date/Time
                </th>
                <th>
                    Symbol
                </th>
                <th>
                    Shares
                </th>
                <th>
                    Price
                </th>
            </tr>
        </thead>
        <tbody>
            <?php
                foreach ($transactions as $row)
                {
                    print("<tr>");
                    print("<td>" . $row["type"] . "</td>");
                    print("<td>" . $row["time"] . "</td>");
                    print("<td>" . $row["symbol"] . "</td>");
                    print("<td>" . $row["shares"] . "</td>");
                    print("<td>" . $row["price"] . "</td>");
                    print("</tr>");
                }
            ?>
        </tbody>
    </table>
</div>
