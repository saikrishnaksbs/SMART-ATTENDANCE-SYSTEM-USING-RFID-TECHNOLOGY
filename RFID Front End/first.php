<html>
<head>
<script language="Javascript">
<!--
function OnButton1()
{
    document.form1.action = "process.php"
}
-->
</script>
<title>Smart Attendance Management System</title>
</head>
<body>
<style>
body{
background-image: url("Light1.jpg");
}
</style>
<center>
<img src="Capture.png" alt="ANITS" style="width:900px;height:145px;">
<h1><font face="Lucida Calligraphy" color="black">Department Of CSE</font></h1>
<h2>WELCOME TO ATTENDANCE SECTION</h2></center>
<center>
<h3>Enter your Login Credentials:</center>
<center>
<form  name="form1" method="POST">
<h4>Username:<input type="text" id="username" name="username"/></h4>
<h4>Password:<input type="password" id="password" name="password"/></h4>
<input type="submit" id="btn"  value="Login!" onclick="OnButton1(); "/>

</form>
</center>
</head>
</html>