<form action="sell.php" method="post">
    <fieldset>
        <label>Sell Stocks</label>
        <div class="form-group">
            <select class="form-control" name="symbol">
                <option disabled selected value="">Symbol</option>
                <?php 
                    foreach ($userStocks as $stock)
                    {
                        print("<option value='" . $stock["symbol"] . "'>" . $stock["symbol"] . "</option>");
                    }
                ?>
            </select>
        </div>
        <div class="form-group">
            <input autocomplete="off" class="form-control" name="shares" placeholder="Shares" type="text"/>
        </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit">Sell</button>
        </div>
    </fieldset>
</form>