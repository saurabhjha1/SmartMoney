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
	unset($_GET['msg']);
}
?>
<br />

<?php


$user_name = "root";
$password = "root";
$database = "SmartMoney";
$server = "127.0.0.1";
$connection = mysql_connect($server, $user_name, $password);
$db_found = mysql_select_db($database);


?>

<?php
	// Now retrieve previously updated profile information
	$sql_profile = "SELECT * FROM profile_info WHERE uid=" . $_SESSION['srollno'];
	$sql_interests = "SELECT * FROM choices WHERE uid=" . $_SESSION['srollno'];

	$q = mysql_query($sql_profile) or die("Couldn\'t grab profile Info!");
	$r = mysql_query($sql_interests) or die("Couldn\'t grab profile Info!");

	// Initialize all values
	$gender = 'male';
	$interests = array(0, 0, 0);
	$secq = null;
	$seca = null;

	foreach($row = mysql_fetch_array($q) as $k => $v) {
		if($k == 'gender')
			$gender = $v;
		if($k == 'security_question')
			$secq = $v;
		if($k == 'security_answer')
			$seca = $v;
	}

	foreach($row = mysql_fetch_array($r) as $k => $v) {
		if($k == 'trekking')
			$interests[0] = $v;
		if($k == 'coding')
			$interests[1] = $v;
		if($k == 'tv')
			$interests[2] = $v;
	}
} else { ?>
	<h4>Whoa! It looks like you haven't updated your profile yet!</h4>
<?php
}

// Step 2: Display the form
?>
<form action="saveProfile.php?f=<?php echo (int)$fFlag; ?>" method="POST">
  <fieldset>
     <legend>Profile</legend>
	<label for="gender_id">Gender:</label>
	<input type="radio" id="gender_id" name="gender" value="male" <?php if($fFlag) if($gender == 'male') echo 'checked="checked"'; ?> /> Male
	<input type="radio" id="gender_id_0" name="gender" value="female" <?php if($fFlag) if($gender == 'female') echo 'checked="checked"'; ?> /> Female

	<hr /> <!-- Beautify with horizontal rule -->

	<label for="interests_id">Interests:</label>
	<input type="checkbox" id="interests_id" name="interests[]" value="trekking" <?php if($fFlag) if($interests[0]) echo 'checked="checked"'; ?> /> Trekking
	<input type="checkbox" id="interests_id_1" name="interests[]" value="coding" <?php if($fFlag) if($interests[1]) echo 'checked="checked"'; ?> /> Coding
	<input type="checkbox" id="interests_id_2" name="interests[]" value="tv" <?php if($fFlag) if($interests[2]) echo 'checked="checked"'; ?> /> TV

	<hr /> <!-- Beautify -->

	<label for="security_question_id">Security Question:&nbsp;</label>
	<input type="text" id="security_question_id" name="secq" <?php if($fFlag) if(isset($secq)) echo 'value="'. $secq . '"'; ?> />

	<br />

	<label for="security_answer_id">Security Answer:&nbsp;&nbsp;</label>
	<input type="text" id="security_answer_id" name="seca" <?php if($fFlag) if(isset($seca)) echo 'value="'. $seca . '"'; ?> />

	<hr />

	<input type="submit" value="Save" name="save" />
  </fieldset>
</form>
<?php

?>
</body>
