<?php
session_start();

$uname1 = "";
$pwd = 0;
$rollno = "";

if ($_SERVER['REQUEST_METHOD'] == 'POST')
 {
$uname1 = $_POST['uname'];
$pwd = $_POST['pw'];


}

$user_name = "root";
$password = "root";
$database = "SmartMoney";
$server = "127.0.0.1";
$connection = mysql_connect($server, $user_name, $password);

$status=0;
if ($db_found = mysql_select_db($database)) {
	$query ="SELECT * FROM `user`";

	$result = mysql_query($query) or die("Query failed:".mysql_error());
	
	while($row = mysql_fetch_array($result))
	{
		
		$tpw     = $row['Password'];
		$sname 	 = $row['User_id'];

		if (($uname1==$sname) && ($pwd==$tpw)) 
		{
			$_SESSION['srollno'] = $trollno;
			$_SESSION['sname']= $sname;
			echo "Success";
			$status=1;
			header("Location: successlogin.php");
		}
	}
	if($status==0){
	echo "<br/>Incorrect information provided";
	}
	
	mysql_close($connection);
}
else {
	print "DATABASE NOT FOUND ";
}
