<?php 
	session_start();
	include("include/commun.php");
	//Recupération des données en session
	$idUtilisateur=$_SESSION["idUtilisateur"];
	$idFamille=$_SESSION["idFamille"];
	$idMembre=$_POST["idMembre"];
	$reqMembre=mysql_query("Select prenomMembre,loginMembre,passMembre,nomMembre from membre where idMembre=".$idMembre." and idFamille=".$idFamille." ;");
	
	$line=mysql_fetch_array($reqMembre);
	$prenomMembre=$line["prenomMembre"];
	$nomMembre=$line["nomMembre"];
	$loginMembre=$line["loginMembre"];
	$passMembre=$line["passMembre"];
	if(isset($_POST["Valider2"])&& $_POST["Valider2"]=="Valider")
	{
		$idMembre=$_POST["Num"];
		//recuperation des données
		$prenomMembre=$_POST["Prenom"];
		$nomMembre=$_POST["Nom"];
		$loginMembre=$_POST["Login"];
		$passMembre=$_POST["Password"];
		$Resp=$_POST["Resp"];
		$resUpdateMembre=mysql_query("update membre set prenomMembre='".$prenomMembre."',loginMembre='".$loginMembre."'
		,passMembre='".$passMembre."',nomMembre='".$nomMembre."'  where idMembre=".$idMembre." and idFamille=".$idFamille);
			
		if($Resp==1)
		{
			$resUpdateFamille=mysql_query("update famille set respId=".$idMembre." where idFamille=".$idFamille);
			
		}
			echo '<script language="Javascript">
					<!--
					var t=setTimeout("document.location.replace(\'Application.php\')");
					// -->
					// </script>';
	}
	if(isset($_POST["Retour"])&& $_POST["Retour"]=="Retour")
	{
			echo '<script language="Javascript">
					<!--
					var t=setTimeout("document.location.replace(\'Application.php\')");
					// -->
					// </script>';
	}
?>
<html>
 <?php include("include/commun.php");
  include ("include/header.php");?>
  <center>
	<div name="contenu" class="contenu">
 	<center>
        <h2>
            <u>
                <b>
                    
                    Veuillez vous remplir ou modifier les champs ci-dessous.
                    
                </b>
            </u>
        </h2>
        <br />
        <form name="ModifMembre" action="" method="post" >
        <table class="tableInscrip">
            <tr>
            	<td>Nom:</td>
                <td><input type="text" name="Nom" value="<?php echo $nomMembre ?>"/> <input type="hidden" name="Num" value="<?php echo $idMembre ?>"/></td>
            </tr>
            <tr>
            	<td>Prenom:</td>
                <td><input type="text" name="Prenom" value="<?php echo $prenomMembre?>"/> </td>
            </tr>
            <tr>
            	<td>Login:</td>
                <td><input type="text" name="Login" value="<?php echo $loginMembre?>"/> </td>
            </tr>
            <tr>
            	<td>Password:</td>
                <td><input type="text" name="Password" value="<?php echo $passMembre?>"/> </td>
            </tr>    
            <tr>
            	<td>Est il administrateur de la famille ?:</td>
                <td>Oui <input type="radio" name="Resp" value="1"> non <input type="radio" name="Resp" checked value="0"> </td>
            </tr>
              <tr>
            	<td><input type="submit" name="Valider2" value="Valider" /></td>
                <td><input type="submit" name="Retour" value="Retour" /> </td>
            </tr>
            
        </table>
        </form>
        </center>
	</div>
 </center>
</body>
</html>
<?php include ("include/footer.php");?>