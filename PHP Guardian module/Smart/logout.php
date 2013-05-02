<?php
session_start();

// Check if logged in first
if(isset($_SESSION['srollno']) && isset($_SESSION['sname'])) {
	unset($_SESSION['srollno']);
	unset($_SESSION['sname']);
	session_destroy();
}

header("Location: login.php");
