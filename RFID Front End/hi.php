<?php
date_default_timezone_set('Asia/Kolkata');
$date = date('Y-m-d H:i:s');
echo $date;
$timezone = date_default_timezone_get();
echo "The current server timezone is: " . $timezone;
?>