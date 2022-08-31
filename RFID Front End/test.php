<?php
date_default_timezone_set('Asia/Kolkata');
$date = date('Y-m-d H:i:s');
    $dbusername = "root";
    $server = "localhost"; 
    $dbconnect = mysqli_connect($server, $dbusername);
    $dbselect = mysqli_select_db($dbconnect,"rfid");
    $sql = "INSERT INTO tags (value,time) VALUES ('".$_GET["value"]."','$date')";    
    mysqli_query($dbconnect,$sql);
?>