package com.example.ldcorig;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.util.SparseBooleanArray;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.SimpleAdapter;
import android.widget.Spinner;
import android.widget.Toast;

import java.net.MalformedURLException;
import java.net.URI;
import java.net.URISyntaxException;
import java.net.URL;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import com.example.listedecourse.R;

/**
 * Classe gérant le comportement de l'activité Magasin Cette activité a pour
 * fonctionnalités:
 * <ol>
 * <li>L'affichage des rayons du magasin(toujours)
 * 
 * <li>L'ajout d'un nouveau rayon lorsque la zone de saisie nomRayon est remplie
 * et que l'utilisateur clique sur le bouton "Ajouter"
 * 
 * <li>La supression des rayons sélectionnés par l'utilisateur
 * </ol>
 */
public class ConnexionActivity extends BaseActivity {
	// code s'exécutant à la création de l'activité

	private Button boutonConnexion;
	private Button boutonInscription;
//	private Button boutonCreerFamille;
	private EditText txtLogin;
	private EditText txtMdp;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		// on charge la bonne interface (layout)
		setContentView(R.layout.activity_connexion);
		boutonConnexion = (Button) findViewById(R.id.buttonConnexion);
		boutonInscription = (Button) findViewById(R.id.buttonInscription);
		boutonConnexion.setOnClickListener(new AdapterView.OnClickListener() {

			@Override
			public void onClick(View v) {
				String txtLogin = ((EditText) findViewById(R.id.editTextLogin)).getText().toString();
				String txtMdp = ((EditText) findViewById(R.id.editTextMdp)).getText().toString();
				String adresse = baseUrl
						+ "Connexion.php?login='" + txtLogin
						+ "'&mdp='" + txtMdp + "'";
				Log.i("ListeDeCourse", adresse);
				accessWebService(adresse);
			}
			
		});
		boutonInscription.setOnClickListener(new AdapterView.OnClickListener() {

			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				  String url = "http://10.0.2.2/cours/SiteNewWorld/Inscription.php";
	                Intent i = new Intent(Intent.ACTION_VIEW);
	                i.setData(Uri.parse(url));
	                startActivity(i);
			}
			
			
		});
	}
	
	@Override
	public String url() {
		return baseUrl + url;
	};

	@Override
	void traiterDonneesRecues(String jsonResult) {
		//Log.i("ListeDeCourse", "the json" + jsonResult);
		try {
			JSONObject jsonResponse = new JSONObject(jsonResult);
			JSONArray jsonMainNode = jsonResponse
					.optJSONArray("connexion");			
			if (jsonMainNode != null) {// si c'est la liste des rayons
				// for de parcours du json
				//for (int i = 0; i < jsonMainNode.length(); i++) {
					JSONObject jsonChildNode = jsonMainNode
							.getJSONObject(0);
					String log = jsonChildNode.optString("retourConnec");
					Log.i("ListeDeCourse", "the log" + log);
			//	}// fin du for de parcours du json
				if(log.equals("0")){
					Intent i = new Intent(this,FaireCourseActivity.class );startActivity(i);finish();
				}
				try {
					// on associe l'adaptateur au spinner des rayons
				//	spinnerRayon.setAdapter(sARayon);
					// on va chercher la liste de course en cours
					//String adresse = baseUrl + url;
					//accessWebService(adresse);
				} catch (NullPointerException e) {
					Log.i("ListeDeCourse", "pointeur null");
				}
			}
		} // 
		catch (JSONException e) {
			Toast.makeText(getApplicationContext(), "Error" + e.toString(),
					Toast.LENGTH_SHORT).show();
		}
	}
	

}
