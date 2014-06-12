<?php
include("include/commun.php");
function AfficherProduit($id)
{
$reponse = new xajaxResponse();//Création d'une instance de xajaxResponse pour traiter les réponses serveur
$produit='';// Initialisation de la variable $produit
//la selection des produits selon le code du rayon choisi
$req = mysql_query("SELECT `produitLib`,`produitId` FROM `produit` where rayonId=".$id) or die(mysql_error()); 

$produit .='<form name="AjoutProd" method="post" action="" ><center>Produit :<select name="produit" id="produit">';
$produit .='<option value="00">Selectionnez votre produit</option>';

  while($array = mysql_fetch_array($req))
{

               $produit .='<option value="'.$array['produitId'].'">'.$array['produitLib'].'</option>';
               
}
$produit .='</select></center>Quantit&eacute; : <input type="text" class="only_float" name="Quantite" /><br><input type="submit" name="AjoutProd" value="Ajouter"/></form>';
$reponse = new xajaxResponse('ISO-8859-1');
$reponse->addAssign("affProduit","innerHTML",$produit);
return $reponse->getXML();
}
require("xajax.inc.php");
$xajax = new xajax(); //On initialise l'objet xajax
$xajax->setCharEncoding('ISO-8859-1');
$xajax->decodeUTF8InputOn();
$xajax->registerFunction("AfficherProduit");
$xajax->processRequests();//Fonction qui va se charger de faire les requetes APRES AVOIR DECLARER NOS FONCTIONS
session_start();?>
    <?php
    //Recupération des données en session
$idUtilisateur=$_SESSION["idUtilisateur"];
$idFamille=$_SESSION["idFamille"];
$resResp=mysql_query("select idMembre from membre where idMembre=(select respId from famille where idFamille=".$idFamille.") and idFamille=".$idFamille."; ");
$lineResp=mysql_fetch_array($resResp);
$numResp=$lineResp["idMembre"];
$resListe=mysql_query("select listeId from liste  where familleId=".$idFamille." and encours=1");

//----------------------------------------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------Caddy--------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------//
//Si le produit est mis dans le caddy
if(isset($_POST["Caddy"])&& $_POST["Caddy"]=="Caddy")
{
		$res=mysql_query("select contenuListe.produitId as produitId,listeId from contenuListe natural join liste inner join produit on produit.produitId=contenuListe.produitId where familleId=".$idFamille." and encours=1");
		while($line=mysql_fetch_array($res))
		{
			$listeId=$line["listeId"];
			$id=$line["produitId"];
			
			if(isset($_POST["".$id.""]))
			{
			$resCaddy=mysql_query("update contenuListe set dansCaddy=1 where produitId=".$id." and listeId=".$listeId." ;");
			}
		}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------Reporter-----------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//Si on reporte le produit aux prochaines courses
if(isset($_POST["Reporter"])&& $_POST["Reporter"]=="Reporter")
{
		//on Recupere liste la plus récente de la famille
		$resNumListe=mysql_query("select MAX(listeId) as max from liste where familleId=".$idFamille." ");
		$line=mysql_fetch_array($resNumListe);
		$numListe=$line["max"];
		//recuperation de la liste en cours
		$resListeEnCours=mysql_query("select listeId,magasinId from liste where familleId=".$idFamille." and encours=1");
		$lineListeEnCours=mysql_fetch_array($resListeEnCours);
		$noListeEnCours =$lineListeEnCours["listeId"];
		$magasinID=$lineListeEnCours["magasinId"];
			if ($numListe==$noListeEnCours)
			{
				$resMaxListe2=mysql_query("select MAX(listeId)+1 as max from liste");
				$lineMax=mysql_fetch_array($resMaxListe2);
				$num=$lineMax["max"];
				if ($num==""){$num=0;}
				$num=$num+1;
				$resAddListe=mysql_query("insert into liste(listeId,familleId,encours,dateCreation,magasinId) 
				values (".$num.",".$idFamille.",0,Current_Date(),"
				.$magasinID.");");
				$res1=mysql_query("select contenuListe.produitId as produitId,listeId from contenuListe natural join liste inner join produit 
				on produit.produitId=contenuListe.produitId where familleId=".$idFamille." and encours=1");
				
				while($line=mysql_fetch_array($res1))
				{
					$noListeEnCours=$line["listeId"];
					$id=$line["produitId"];
					
					//si ils sont selectioné, les produit sont repporter
					
					if(isset($_POST["".$id.""]))
					{
							$sql="update contenuListe set listeId=".$num." where produitId=".$id." and listeId=".$noListeEnCours.";";
							$res=mysql_query($sql);
					}
				}
			}
			else
			{

				$res2=mysql_query("select contenuListe.produitId as produitId,listeId from contenuListe natural join liste inner join produit 
				on produit.produitId=contenuListe.produitId where familleId=".$idFamille." and encours=1;");
				
				
				while($line2=mysql_fetch_array($res2))
				{
					$id=$line2["produitId"];
					
					//si ils sont selectioné, les produit sont repporter
					
					if(isset($_POST["".$id.""]))
					{
							$sql="update contenuListe set listeId=".$numListe." where produitId=".$id." and listeId=".$noListeEnCours." ;";
							$res=mysql_query($sql);
					}
				}
			//echo $noListeEnCours." test";
			}
}
//----------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------Annuler----------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------//
//Si le produit n'a pas a etre pris 
if(isset($_POST["Annuler"])&& $_POST["Annuler"]=="Annuler")
{
		$res=mysql_query("select contenuListe.produitId as produitId,listeId from contenuListe natural join liste inner join produit on produit.produitId=contenuListe.produitId where familleId=".$idFamille." and encours=1");
		while($line=mysql_fetch_array($res))
		{
			$listeId=$line["listeId"];
			$id=$line["produitId"];
			
			if(isset($_POST["".$id.""]))
			{
			$resCaddy=mysql_query("delete from contenuListe where produitId=".$id." and listeId=".$listeId." ;");
			}
		}
}
//----------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------AjouterMembre----------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------//
//Si le produit n'a pas a etre pris 
if(isset($_POST["Ajouter"])&& $_POST["Ajouter"]=="Valider")
{
	//recuperation des données
	$nomFamille=$_POST["NomFamille"];
	$Prenom=$_POST["Prenom"];
	$Login=$_POST["Login"];
	$Password=$_POST["Password"];
	
	$resIdMembre=mysql_query("Select max(idMembre) as maxId from membre where idFamille=".$idFamille);
	$lineId=mysql_fetch_array($resIdMembre);
	$maxID=$lineId["maxId"];
	
	$resAjoutMembre=mysql_query("insert into membre (idMembre,idFamille,prenomMembre,loginMembre,passMembre,dateCreation,nomMembre)
					values(".$maxID.",".$idFamille.",'".$Prenom."','".$Login."','".$Password."',CURDATE(),'".$nomFamille."')");
}
if(isset($_POST["AjoutProd"])&& $_POST["AjoutProd"]=="Ajouter")
{
	//recuperation des données
	$idProduit=$_POST["produit"];
	$Quantite=$_POST["Quantite"];
	$resSelectListe=mysql_query("select listeId from liste where familleId=".$idFamille." and encours=1");
	$lineListe=mysql_fetch_array($resSelectListe);
	$idListe=$lineListe["listeId"];
	$resNb=mysql_query("select count(*) as nb from contenuListe where produitId=".$idProduit." and listeId=".$idListe.";");
	$line=mysql_fetch_array($resNb);
	$nb=$line["nb"];
		if($nb==0)
		{
			$resAjoutProduit=mysql_query("insert into contenuListe (listeId,produitId,listeQte,dansCaddy)
					values(".$idListe.",".$idProduit.",".$Quantite.",0)");
		}
		else
		{
			$result=mysql_query("update contenuListe set listeQte=listeQte+".$Quantite." ,dansCaddy=0 where produitId=".$idProduit." and listeId=".$idListe.";");
		}
		
		
	
}
?>
<html>
<?php include ("include/header.php");
$xajax->printJavascript(); /* Affiche le Javascript */?>
<center>
<div name="contenu" class="contenu">
	<center>
    	<table class="appli">    	
            <th onClick="showdiv(1)">
                Remplir la liste
            </th>
         
            <th onClick="showdiv(2)">
                Faire les courses
            </th>
            <?php
			if ($numResp==$idUtilisateur)
			{
			echo"<th onClick='showdiv(3)'>
                Gerer la famille
            	</th>";
			}
			?>
       	</table>
        <!-- ----------------------------------------------------------------Remplir Les courses -------------------------------------->
       <div id="contenu_1" class="divApp">
           <h5>
               <u>
               		Votre liste de course en cours:
               </u>
           </h5>
           <br />
           <table class="liste">
           		<th>
                	Produit
                </th>
                <th>
                	Quantité
                </th>
                
                	<?php
						$res=mysql_query("select contenuListe.produitId as produitId ,produitLib,listeQte from contenuListe natural join Liste inner join produit 
						on produit.produitId=contenuListe.produitId where familleId=".$idFamille." and encours=1 and dansCaddy=0");
						/*echo "select contenuListe.produitId as produitId ,produitLib,listeQte from contenuListe natural join Liste inner join produit 
						on produit.produitId=contenuListe.produitId where familleId=".$idFamille." and encours=1 and dansCaddy=0";*/
						while($line=mysql_fetch_array($res))
						{
							$lib=$line["produitLib"];
							$qte=$line["listeQte"];	
							echo "<tr>";
							echo "<td class='tdListe'>".$lib."</td>";
							echo "<td class='tdListe'>".$qte."</td>";
							echo "</tr> "; 
						}
					?>   	
           </table>
           <hr>
           	<center>
                        	Rayon: <select name="rayon" id="rayon" onChange="xajax_AfficherProduit(document.getElementById('rayon').value);">
                            <option value="00">Choisissez un rayon</option>
                            <?php
								$reqRayon=mysql_query(" select rayonId, rayonLib from Rayon");
								while($lineRayon=mysql_fetch_array($reqRayon))
								{
									$id=$lineRayon["rayonId"];
									$lib=$lineRayon["rayonLib"];
									?>
                                    <option value="<?php echo $id ?>" ><?php echo $lib ?></option> 
                                    <?php
								}
							?>
                            </select>
                            <div id="affProduit" name ="affProduit" >
                            </div>
                        </center>
       </div>
       <!-- ----------------------------------------------------------------Faire Les courses -------------------------------------->
       <div id="contenu_2" class="divApp">
       		<h5>Faire les courses</h5>
            <br />
            <form name="FaireCourse" action="" method="post">
             <table class="liste">
           		<th>
                	Produit
                </th>
                <th>
                	Quantité
                </th>
                <th>
                	Action
                </th>
            <?php
						$res=mysql_query("select contenuListe.produitId as produitId ,produitLib,listeQte from contenuListe natural join Liste inner join produit on produit.produitId=contenuListe.produitId where familleId=".$idFamille." and encours=1 and dansCaddy=0");
						while($line=mysql_fetch_array($res))
						{
							$id=$line["produitId"];
							$lib=$line["produitLib"];
							$qte=$line["listeQte"];	
							echo "<tr>";
							echo "<td class='tdListe'>".$lib."</td>";
							echo "<td class='tdListe'>".$qte."</td>";
							echo "<td class='tdListe'><INPUT type='checkbox' name='".$id."'>";
							echo "</tr> "; 
						}
					?>
           </table>
           <input type="submit" name="Caddy" value="Caddy"><input type="submit" name="Reporter" value="Reporter"><input type="submit" name="Annuler" value="Annuler">
           </form>
       </div>
       <!-- ----------------------------------------------------------------Gerer sa famille -------------------------------------->
        <div id="contenu_3" class="divApp">
        <h5>Gerer sa famille</h5>
            <br />
             <table class="liste">
               <th>
                	Nom
                </th>
           		<th>
                	Prenom
                </th>
                <th>
                	login
                </th>
                <th>
                	Password
                </th>
                <th>
                	action
                </th>
                <?php
				
            	//recuperation des informations des membre de la famille
				$resMembre=mysql_query("select idMembre,prenomMembre,loginMembre,passMembre,nomMembre from membre where idMembre!=".$idUtilisateur." and idFamille=".$idFamille."");
				$i=0;
				while($lineMembre=mysql_fetch_array($resMembre))
				{
					$i++;
					echo "<tr>";
				echo " <form name='Famille".$i."' action='Details.php' method='post'>";
					//recuperation des données de la requete
					$idMembre=$lineMembre["idMembre"];
					$prenomMembre=$lineMembre["prenomMembre"];
					$loginMembre=$lineMembre["loginMembre"];
					$passMembre=$lineMembre["passMembre"];
					$nomMembre=$lineMembre["nomMembre"];
					
					echo"<td class='tdListe'>";
					echo "<input type='hidden' name='idMembre' value='".$idMembre."' /> ".$nomMembre ;
					echo"</td>";
					
					echo"<td class='tdListe'>";
					echo $prenomMembre ;
					echo"</td>";
					
					echo"<td class='tdListe'>";
					echo $loginMembre ;
					echo"</td>";
					
					echo"<td class='tdListe'>";
					echo $passMembre ;
					echo"</td>";
					
					echo"<td class='tdListe'>";
					echo "<input type='submit' name='Details' value='Modifier' />" ;
					echo"</td>";
					echo "</form>";
				echo "</tr>";
				}
						
				?>
               </table>
               <hr>
               <center>
               	<h5>
                	Ajoutez un membre dans votre famille:
                </h5>
                <form name="AjoutFamille" action="" method="post">
                
                <table class="liste">
                <tr>
            <td class="tdListe">Nom de famille:</td>
            <td class="tdListe"><input type="text" name="NomFamille"></td>
        </tr>
        <tr>
             <td class="tdListe">Prenom:</td>
            <td class="tdListe"><input type="text" name="Prenom"></td>
        </tr>
        <tr>
            <td class="tdListe">Login:</td>
            <td class="tdListe"><input type="text" name="Login"></td>
          </tr>
          <tr>
             <td class="tdListe">Password:</td>
            <td class="tdListe"><input type="Password" name="Password"></td>
            
        </tr>
        </table>
                <table>
                   <tr>
             <td ><center><input type="submit" name="Ajouter" value="Valider"></center></td>
            <td ><center><input type="submit" name="Retour" value="Retour"></center></td>
        </tr>
                </table>
               </center>
           </form>
        </div>
</center>
</div>
<a href="index.php" > Deconnection</a>
</center>
</body>
</html>
<?php include ("include/footer.php");?>