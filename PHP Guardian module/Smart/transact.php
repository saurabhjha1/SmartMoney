 <?php 
 // Connects to your Database 
 mysql_connect("localhost", "root", "root") or die(mysql_error()); 
 mysql_select_db("SmartMoney") or die(mysql_error()); 
 $data = mysql_query("SELECT * FROM `tansactionHistory`") 
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
