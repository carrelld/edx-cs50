<div class="container">
    <div id="change-password" class="account-container">
        <form action="account.php" method="POST">
            <label>Change Password</label>
            <input type="password" name="password" placeholder="New Password"/>
            <input type="password" name="confirmation" placeholder="Confirm New Password"/>
            <input type="hidden" name="form" value="changepassword"/>
            <input type="submit" value="Change Password"/>
        </form>
    </div>
    <div id="add-funds" class="account-container">
        <form action="account.php" method="POST">
            <label>Add funds</label>
            <input type="text" name="amount" placeholder="1000.00"/>
            <input type="hidden" name="form" value="addfunds"/>
            <input type="submit" value="Add Funds"/>
        </form>
    </div>
</div>