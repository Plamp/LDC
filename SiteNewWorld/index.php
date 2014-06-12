<?php
session_destroy();
session_start();
include("include/commun.php");
if(isset($_POST["connexion"])&& $_POST["connexion"]=="Valider")
{
	$login=$_POST["login"];
	$mdp=$_POST["mdp"];
	$res=mysql_query("select identification('".$login."','".$mdp."') as connection;");
	$line=mysql_fetch_array($res);
	$retourConnec=$line["connection"];
	echo "select identification('".$login."','".$mdp."') as connection;";
	//echo $retourConnec." test";
	if($retourConnec==0)
	{
		$res=mysql_query("select idMembre,idFamille from membre where loginMembre='".$login."' and passMembre='".$mdp."' ;");
		$line2=mysql_fetch_array($res);
		$_SESSION["idUtilisateur"]=$line2["idMembre"];
		$_SESSION["idFamille"]=$line2["idFamille"];
		echo '<script language="Javascript">
  			<!--
  			var t=setTimeout("document.location.replace(\'Application.php\')");
			// -->
			// </script>';
	}
	else
	{
		//message d'erreur
	}
}
?>
  <html>
  <?php include ("include/header.php");?>
<center>
    <div name="contenu" class="contenu">
    <h2>
        <u>
            <b>
                <center>
                    Veuillez vous connectez pour accéder à l'application.
                </center>
            </b>
        </u>
    </h2>
    <br/>
    <center>
        <form name="RecupConnexion" method="post" action="">
            <table class="connexion">
                <tr>
                    <td>
                        Identifiant:
                    </td>
                    <td>
                        <input type="text" name="login" />
                    </td>
                </tr>
                <tr>
                    <td>
                        Mot de passe:
                    </td>
                    <td>
                        <input type="password" name="mdp" />
                    </td>
                </tr>
           </table>
           <input type="submit" name="connexion" class="boutonCo" value="Valider"/>
        </form>
        <a href="./Inscription.php">Ou inscrivez vous en créant une famille</a>
    </center>
    </div>
    </center>
</body>
</html>
<?php include ("include/footer.php");?>