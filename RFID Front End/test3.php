<?php
$data=$_POST['rnumber'];
$conn=mysqli_connect("localhost","root");
$db=mysqli_select_db($conn,"rfid");
$h=mysqli_query($conn,"select regno from details where regno='$data'" );
$f=mysqli_fetch_assoc($h);
$g=$f['regno'];
$sql="select * from details where regno='$g'";
		$records=mysqli_query($conn, $sql);
 ?>
<html>
<head>
<title>ANITS::Procturing</title>
<style>
body{
background-image: url("Light1.jpg")
}
</style>
<center>
<?php
while($student1=mysqli_fetch_array($records)){
	?>
<h1><font face="Lucida Calligraphy" color="Black" size="1500">Student Details:</font></h1><br><br>
<font face="Baskerville Old Face"><center>STUDENT NAME:&nbsp</font><font face="Britannic"><?php 
echo  $student1['name'];?><br></font>
<font face="Baskerville Old Face"><center>STUDENT ROLL NO:&nbsp</font><font face="Britannic"><?php 
echo $student1['regno'];?><br></font>
<font face="Baskerville Old Face"><center>STUDENT PHONE NUMBER:&nbsp</font><font face="Britannic"><?php 
echo $student1['phno'];?></font><br>
<font face="Baskerville Old Face"><center>STUDENT RFID SERIAL:&nbsp</font><font face="Britannic"><?php 
echo $student1['tagserial'];?></font><br>
<?php
}
?>
<?php
$h1=mysqli_query($conn,"select time from tags" );
$f1=mysqli_fetch_assoc($h1);
$g1=$f1['time'];
?>
<font face="Baskerville Old Face"><center>STUDENT ENTRY TIME:&nbsp</font><font face="Britannic"><?php 
echo $g1;?></font>
</center>
</html>