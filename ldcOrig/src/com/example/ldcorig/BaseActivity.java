package com.example.ldcorig;
import com.example.listedecourse.R;

import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;

public abstract class BaseActivity extends Activity {
	
	
//quelques propriétés de la classe:
     //adresse du web service qui fournit les données
	 protected String url;//metinan.besaba.com/coursesOrig/
	 protected String baseUrl="http://10.0.2.2/cours/CoursesOrig/";
	 //accesseur à implémenter dans chaque classe descendante
	  abstract String url();
	 //code s'exécutant à la création de l'activité (constructeur) 
	protected void onCreate(Bundle savedInstanceState) {
		//appel du constructeur hérité de la classe Activity
		super.onCreate(savedInstanceState);
		//demande asynchrone de données par le web
		accessWebService(url());		
	}
	
//chargement des actions du menu
	public boolean onCreateOptionsMenu(Menu monMenu) {
	    // On va charger dans la barre d'action les elements du menu définis dans res/menu/main.xml
	    MenuInflater monInflater = getMenuInflater();
	    monInflater.inflate(R.menu.main, monMenu);
	    //appel de la même méthode héritée
	    return super.onCreateOptionsMenu(monMenu);
	}
	
//gestion du clic sur les différentes actions
	public boolean onOptionsItemSelected(MenuItem item){
		switch (item.getItemId())
		{
		    //faire les courses
			case R.id.action_courses: Intent i = new Intent(this,FaireCourseActivity.class );startActivity(i);finish();break;
			//ranger les rayons dans le magasin
			case R.id.action_connexion: Intent i1 = new Intent(this,ConnexionActivity.class );startActivity(i1);finish();break;			
			//remplir la liste de course
			case R.id.action_liste: Intent i2 = new Intent(this,RemplirListe.class );startActivity(i2);finish();break;	
			/*default:
				return super.onOptionsItemSelected(item);*/
		}		
		return true;
	}
	

	// Tâche Asynchrone qui demande des données à un service web écrit en php

	 
	 public void accessWebService(String adresse) {
	  //instanciation de la classe WebServiceClient
	  WebServiceClient monWebService = new WebServiceClient(new InterfaceDeCallBack() {

          @Override
          public void receptionDonneesTerminee(String result) {
        	  traiterDonneesRecues(result);
          }
      });
	  // on envoie l'adresse du webService à atteindre
	  monWebService.execute(new String[] { adresse });
	 }
    //Ici on ne sait pas quoi faire des données mais dans les classes descendantes on le saura
	abstract void  traiterDonneesRecues(String result);
	 
}//fin de la classe BaseActivity
