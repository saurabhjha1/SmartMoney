<?php             

session_start(); 
$sroll =$_SESSION['srollno'];
$sn =$_SESSION['sname'];
?>
<html>
<head>
<title>Transaction History of your ward</title>
</head>
<body>
welcome Mr <?php echo $sn; ?>
<br />
<a href="logout.php">Logout</a>
<br />
<?php
if(isset($_GET['msg'])) {
	echo '<h3>' . $_GET['msg'] . '</h3>';
	unset($_GET['msg']); `FrmAccount`='' OR  `ToAccount`=''
}
?>
<br />

 <?php 
 // Connects to your Database 
 mysql_connect("localhost", "root", "root") or die(mysql_error()); 
 mysql_select_db("SmartMoney") or die(mysql_error()); 
 $myquery="SELECT `user_id` FROM `student` WHERE `Guardian_id`=`".$sn."`";
 $data1=mysql_query($myquery);
 $info1=mysql_fetch_array( $data1 );
 $data = mysql_query("SELECT * FROM `tansactionHistory` where  `FrmAccount`=`".$info1['user_id']."` OR `ToAccount`=`".$info1['user_id']."`)" ;
 or die(mysql_error()); 
 Print "<table border cellpadding=3>"; 
 Print "<td><b>From Account</b></td>";
 Print "<td><b>To Account</b></td>";
 Print "<td><b>Amount</b></td>";
 while($info = mysql_fetch_array( $data )) 
 { 
 Print "<tr>"; 
 Print "<td>".$info['FrmAccount'] . "</td> "; 
 Print "<td>".$info['FrmAccount'] . "</td> ";
 Print "<td>".$info['Amount'] . " </td></tr>"; 
 } 
 Print "</table>"; 
 ?> 
</body>
