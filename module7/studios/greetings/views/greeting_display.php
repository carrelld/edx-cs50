<?php

// TODO replace with actual content (e.g. "Cheers, David!")
$message = "Hello, {$recipient_name}!";

// ordinal suffix to num_times field
// Should this be in greet.php? Would that be better MVC design?
$ends = array('th','st','nd','rd','th','th','th','th','th','th');
if (($num_times %100) >= 11 && ($num_times%100) <= 13)
   $num_times_suffix = 'th';
else
   $num_times_suffix = $ends[$number % 10];


// TODO replace 0 with the correct value
$report_num_times = "This is the {$num_times}{$num_times_suffix} time I have said '{$greeting_text}' to someone";

?>

<h2><?= htmlspecialchars($message) ?></h2>
<p><?= htmlspecialchars($report_num_times) ?></p>