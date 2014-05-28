<?php
//version serveur de deploiment
/*
$host="mysql.hostinger.fr"; //replace with database hostname 
$username="u683437950_userl"; //replace with database username 
$password="lcpasswd"; //replace with database password 
$db_name="u683437950_dblis"; //replace with database name
$con=mysql_connect("$host", "$username","$password")or die("cannot connect"); 
mysql_select_db("$db_name")or die("cannot select DB");*/

//version de dev
$host="127.0.0.1"; //replace with database hostname 
$username="root"; //replace with database username 
$password=""; //replace with database password 
$db_name="u683437950_dblis"; //replace with database name
$con=mysql_connect("$host", "$username","$password")or die("cannot connect"); 
mysql_select_db("$db_name")or die("cannot select DB");

//test de co =
/*
echo '<script language="Javascript">
  <!--
  var t=setTimeout("document.location.replace(\'../seConnecter.php\')");
// -->
  //                         // </script>';
  */
?>
