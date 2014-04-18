package com.example.listedecoursedev;

import android.os.Bundle;
import android.text.Selection;
import android.util.Log;
import android.util.SparseBooleanArray;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.AdapterView.OnItemSelectedListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.SimpleAdapter;
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
import org.w3c.dom.Document;

import com.example.listedecourse.R;

/**
 * Classe g�rant le comportement de l'activit� Magasin Cette activit� a pour
 * fonctionnalit�s:
 * <ol>
 * <li>L'affichage des rayons du magasin(toujours)
 * 
 * <li>L'ajout d'un nouveau rayon lorsque la zone de saisie nomRayon est remplie
 * et que l'utilisateur clique sur le bouton "Ajouter"
 * 
 * <li>La supression des rayons s�lectionn�s par l'utilisateur
 * </ol>
 * 
 * @todo Corriger , si le rayon est vide = pas d'action
 */
public class MagasinActivity extends BaseActivity {
	/**
	 * Liste contenant les rayons du magasin
	 */
	private ListView listeViewDesRayons;
	/**
	 * Bouton qui permet à l'utilisateur d'ajouter un nouveau rayon
	 */
	private Button boutonAjouter;
	/**
	 * Bouton qui permet à l'utilisateur de supprimer tous les rayons
	 * sélectionnés
	 */
	private Button boutonSupprimer;
	/**
	 * Zone de saisie pour le nom du nouveau rayon
	 */
	private EditText editTextRayon;
	
	/**
	 * This listener add a new "rayon" when user click on the add button
	 */
	private OnClickListener listenerAjouterRayon = new OnClickListener() {
		@Override
		public void onClick(View v) {
			// For debug purpose only

			Log.i("ListeDeCourse", "Ajout de rayon demandé");
			String nomDuRayon = editTextRayon.getText().toString();

			if (isNewRayon(nomDuRayon)) {
				if (!nomDuRayon.isEmpty()) {
					String adresse = baseUrl
							+ "listeRayons.php?action=ajout&nomRayon="
							+ nomDuRayon;
					URL url;
					try {
						url = new URL(adresse);
						URI uri;
						try {
							uri = new URI(url.getProtocol(), url.getUserInfo(),
									url.getHost(), url.getPort(),
									url.getPath(), url.getQuery(), url.getRef());
							url = uri.toURL();
							adresse = url.toString();
							accessWebService(adresse);
							// We clear editTextRayon
							editTextRayon.getText().clear();
						} catch (URISyntaxException e) {
							e.printStackTrace();
						}

					} catch (MalformedURLException e) {
						e.printStackTrace();
					}
				} else {
					Toast.makeText(getBaseContext(),
							"Le nom de rayon est vide", 3000).show();
					Log.i("ListeDeCourse", "Nom de rayon vide");
				}// fin du "si le champ est vide"

			} else {
				Toast.makeText(getBaseContext(),
						"Le nom de rayon est deja dans la liste", 3000).show();
				// fin du "si le champ est deja rentr�"
			}
		}
	};

	public boolean isNewRayon(String saisie) {
		int nbRayon = listeDesRayons.size();
		for (int i = 0; i < nbRayon; i++) {
			if (listeDesRayons.get(i).getNom().equals(saisie)) {
				return false;
			}
		}
		return true;
	}

	// le listener pour supprimer des rayons (clic sur bouton supprimer)
	private OnClickListener listenerSupprimerRayon = new OnClickListener() {
		@Override
		public void onClick(View v) {
			Log.i("ListeDeCourse", "Suppression demand�e");
			int nombreDeRayon = listeDesRayons.size();
			String adresse = baseUrl + "listeRayons.php?action=delete";
			boolean supressionAEffectuer = false;
			for (int i = 0; i < nombreDeRayon; i++) {
				if (listeDesRayons.get(i).isSelected()) {
					String noDuRayon = listeDesRayons.get(i).getNo();
					adresse += "&tabNoRayon[]=" + noDuRayon;
					supressionAEffectuer = true;
				}
			}// fin du for
			if (supressionAEffectuer)
				accessWebService(adresse);
		}// fin du onClick
	};// fin du OnClickListener

	// quelques propriétés de la classe:
	private String url = "listeRayons.php";

	public String url() {
		return baseUrl + url;
	};

	// liste des rayons
	public List<ModelRayon> listeDesRayons = new ArrayList<ModelRayon>();

	/**
	 * Code s'exécutant après le constructeur lorsque l'activité Magasin est
	 * demandée
	 * 
	 * @param savedInstanceState
	 *            non utilisé pour l'instant
	 */
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// pour debugger
		Log.i("ListeDeCourse",
				"MagasinActivity::onCreate(Bundle savedInstanceState)");
		// appel du constructeur hérité
		super.onCreate(savedInstanceState);
		// on choisit la vue (fichier xml) correspondant à l'activité
		setContentView(R.layout.activity_magasin);
		// on choppe le bouton Ajouter
		boutonAjouter = (Button) findViewById(R.id.buttonAjouterRayon);
		// qu'est-ce qu'on fait qd on clique dessus
		boutonAjouter.setOnClickListener(listenerAjouterRayon);
		// on choppe la zone de saisie du nom du rayon
		editTextRayon = (EditText) findViewById(R.id.editTextNomRayon);
		// on choppe le bouton Supprimer
		boutonSupprimer = (Button) findViewById(R.id.buttonSupprimerRayon);
		// qu'est-ce qu'on fait qd on clique dessus
		boutonSupprimer.setOnClickListener(listenerSupprimerRayon);
		listeViewDesRayons= (ListView) findViewById(R.id.listViewRayons);
	
		
	}// fin du onCreate de la classe/activité

	// charge les données dans les widgets
	@Override
	public void traiterDonneesRecues(String jsonResult) {
		// le webservice répond et on reçoit sa réponse dans la variable
		// "jsonResult"
		// on garde les bonnes habitudes
		Log.i("ListeDeCourse",
				"MagasinActivity::taiterDonneesRecues(String jsonResult)");
		// on vide la listeDesRayons car sinon les rayons reçus seraient
		// ajoutés
		listeDesRayons.clear();
		// obtention de la listeView des rayons (widget défini dans
		// activity_magasin.xml)
		listeViewDesRayons = (ListView) findViewById(R.id.listViewRayons);
		try {
			JSONObject jsonResponse = new JSONObject(jsonResult);
			JSONArray jsonMainNode = jsonResponse.optJSONArray("rayonInfos");
			// pour chaque ligne du tableau des rayons
			for (int i = 0; i < jsonMainNode.length(); i++) {
				JSONObject jsonChildNode = jsonMainNode.getJSONObject(i);
				String nomRayon = jsonChildNode.optString("rayonLib");
				String noRayon = jsonChildNode.optString("rayonId");
				// création du nouveau rayon
				ModelRayon nouveauRayon = new ModelRayon(noRayon, nomRayon);
				// ajout du nouveau rayon à la liste
				listeDesRayons.add(nouveauRayon);
			}// fin du pour
		} catch (JSONException e) {
			Toast.makeText(getApplicationContext(),
					"Erreur: Réponse du webservice incompréhensible",
					Toast.LENGTH_SHORT).show();
		}

		// création de l'adaptateur pour la liste des rayons dans la layout
		// magasin(gestion des rayons)
		RayonAdapter rayonAdapter = new RayonAdapter(this, // le contexte
				listeDesRayons // la liste des rayons
		);
		try {
			// on associe l'adaptateur à la listView
			listeViewDesRayons.setAdapter(rayonAdapter);
		} catch (NullPointerException e) {
			Log.i("ListeDeCourse", "Erreur au chargement des rayons");
		}

	}// fin de traiterDonneesRecues

}// fin de la classe MagasinActivity
