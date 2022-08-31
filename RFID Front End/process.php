<?php
$username1 = $_POST['username'];
$password = $_POST['password'];
$conn=mysqli_connect("localhost","root");
$db=mysqli_select_db($conn,"rfid");
$query=mysqli_query($conn,"select * from faculty where username='$username1' and password='$password'");
$rows=mysqli_num_rows($query);
if($rows==1){
	header('Location:test1.php');
}

else{
echo "Invalid Login Credentials";
}
?>

