<?php
session_start();
include("include/commun.php");?>
<html>
<?php include ("include/header.php");?>
<div name="contenu" class="contenu">
	<center>
    	<table class="appli">    	
            <th onClick="showdiv(1)">
                Remplir la liste
            </th>
         
            <th onClick="showdiv(2)">
                Faire les courses
            </th>
       	</table>
        
       <div id="contenu_1" class="divApp">test1</div>
       <div id="contenu_2" class="divApp">test2</div>
</center>
</div>
</body>
</html>
<?php include ("include/footer.php");?>