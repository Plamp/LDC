<head>
<meta charset="utf-8">
<title>New World</title>
<?php
require_once 'Mobile-Detect-2.8.0/Mobile_Detect.php';
$detect = new Mobile_Detect;

if ( $detect->isMobile() ){
?> <link rel="stylesheet" type="text/css" media="all" href="style-mobile.css" /> <?php
}
else{
?>
<link rel="stylesheet" type="text/css" media="all" href="style.css" /> <?php
}
?>

<script>
	var num_div = 3;
	function showdiv( num ) 
	{
		for (var i=1;i<=num_div;i++) 
		{
			if (i == num ) 
			{
				document.getElementById("contenu_" + i).style.display ="block";
			} 
			else 
			{
				document.getElementById("contenu_" + i).style.display ="none";
			}
		}
	}
	</script>
    <script src="http://code.jquery.com/jquery-latest.js"></script>
<script>
$(document).ready(function() {
// input only floats
	$('body').delegate('input.only_float','keyup',function(){
		if(!$(this).val().match(/^\-?[0-9]*[\.,]?[0-9]*$/))	// numbers[.,]numbers
			remove_last_input(this);
	});
    });
</script>
</head>
<body onLoad="showdiv(1)">
<div class="header">
<center><h1> Bienvenu sur l'application Liste de course de New World !</h1></center>
<br /> 
<hr>
</div>