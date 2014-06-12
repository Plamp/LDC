<?php 
if(isset($_POST["Retour"])&& $_POST["Retour"]=="Retour")
{
		echo '<script language="Javascript">
  				<!--
  				var t=setTimeout("document.location.replace(\'index.php\')");
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
                    
                    Veuillez vous remplir les champs ci-dessous.
                    
                </b>
            </u>
        </h2>
    <br />

<?php
if(isset($_POST["Valider"])&& $_POST["Valider"]=="Valider")
{
	//recuperation des données
	$login=$_POST["login"];
	$mdp=$_POST["mdp"];
	$Cmdp=$_POST["Cmdp"];
	$nomFamille=$_POST["nomFamille"];
	$adresse=$_POST["adresse"];
	$prenomResp=$_POST["prenomResp"];
	$mail=$_POST["mail"];
	//echo "mdp=".$mdp." et cMdp=".$Cmdp;
	//verification de l'unicité du couple mdp/login
	$res=mysql_query("select count(*) as connection from membre where loginMembre='".$login."' ;");
	//echo "select identification('".$login."','".$mdp."') as connection;";
	$line=mysql_fetch_array($res);
	$retourConnec=$line["connection"];
	//echo " ".$retourConnec."test";
		//Traitement des données
		//Si les tests de validation sont fait sans erreur
		if(!($retourConnec!=0 || $mdp!=$Cmdp))
			{
				$res=mysql_query(" select max(idFamille)+1 id,max(codeFamille)+1 code from famille;");
				$infoFamille=mysql_fetch_array($res);
				$idFamille=$infoFamille["id"];
				$codeFamille=$infoFamille["code"];
				//Creation de la famille
				$resAjoutFamille=mysql_query("insert into famille (idFamille,nomFamille,adresseFamille,respid,codeFamille,respMail) 
				values('".$idFamille."','".$nomFamille."','".$adresse."',1,'".$codeFamille."','".$mail."');");
				/*echo " insert into famille (idFamille,nomFamille,adresseFamille,respid,codeFamille) 
				values(".$idFamille.",'".$nomFamille."','".$adresse."',1,".$codeFamille.");";*/
				
				//Creation du responsable de la famille
				$resAjoutMembre=mysql_query("insert into membre (idMembre,idFamille,prenomMembre,loginMembre,passMembre,dateCreation,nomMembre) 
				value(1,".$idFamille.",'".$prenomResp."','".$login."','".$mdp."',Current_Date(),'".$nomFamille."')");
				/*echo "insert into membre (idMembre,idFamille,prenomMembre,loginMembre,passMembre,dateCreation,nomMembre) 
				value(1,".$idFamille.",'".$prenomResp."','".$login."','".$mdp."',Current_Date(),'".$nomFamille."')";*/
				echo '<script language="Javascript">
  				<!--
  				var t=setTimeout("document.location.replace(\'Application.php\')");
				// -->
				// </script>';
			}
		
	/*if(	//Sinon
	{
		//recuperation des numéro auto
		$res=mysql_query("select max(idFamille)+1,max(codeFamille)+1 from famille");
	}*/
}
?>
<br>
<form name="Inscription" action="" method="post">
    <table class="tableInscrip">
       <tr>
            <td class="tdInscript">Identifiant:</td>
            <td><input type="text" name="login" title="Cet identifiant sera utilisé lors de vos connexion au site et aux applications de New world"></td>
       </tr>
       </table><?php 
if(isset($retourConnec)&& $retourConnec!=0)
	{
		echo "<label class='error'>Cet identifiant n'est pas disponible.</label>";
	}
    ?><table class="tableInscrip">

            <tr>   
             <td class="tdInscript">Mot de passe:</td>
            <td><input type="password" name="mdp"></td>
        </tr>
        <tr>   
             <td class="tdInscript">Confirmez: </td>
            <td><input type="password" name="Cmdp">
			 </td>
        </tr>
        </table>

            <?php if(isset($_POST["Valider"])&& $_POST["Valider"]=="Valider")
			{
				//recuperation des données
				$mdp=$_POST["mdp"];
				$Cmdp=$_POST["Cmdp"];
				//si le mot de passe n'est pas le même que la confirmation
				if($mdp!=$Cmdp)
				{
					echo "<label class='error'>Les mots de passe saisient ne correspondent pas.</label>";
				}
			}?>
             
     
    
     <hr style="color:black;width:99%"/>
    
     <table class="tableInscrip">
        <tr>
            <td class="tdInscript">Nom de la famille:</td>
            <td><input type="text" name="nomFamille"></td>
        </tr>
        <tr>
             <td class="tdInscript">Adresse:</td>
            <td><input type="text" name="adresse"></td>
        </tr>
        <tr>
            <td class="tdInscript">Votre prénom:</td>
            <td><input type="text" name="prenomResp"></td>
          </tr>
          <tr>
             <td class="tdInscript">Adresse mail:</td>
            <td><input type="text" name="mail"></td>
            
        </tr>
        <tr>
             <td class="tdInscript"><input type="submit" name="Valider" value="Valider"></td>
            <td class="tdInscript"><input type="submit" name="Retour" value="Retour"></td>
        </tr>
    </table>
    
 	</form>
</center>
</div>
 </center>
</body>
</html>
<?php include ("include/footer.php");?>