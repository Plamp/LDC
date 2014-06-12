package com.example.ldcorig;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.ExpandableListAdapter;
import android.widget.ExpandableListView;
import android.widget.ListView;
import android.widget.SimpleAdapter;
import android.widget.Spinner;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import com.example.listedecourse.R;

public class FaireCourseActivity extends BaseActivity {
	EnsembleDeRayons ensRayons = new EnsembleDeRayons();
	// quelques propriétés de la classe:
	//Cr�ation de l'ensemble de rayon
	
	private String url = "faireCourse.php";
	private Button boutonCaddy;
	private Button boutonReporter;
	private Button boutonAnnuler;
	private AdapterExpandableRayonsProduits monAdapteur;
	public String url() {
		return baseUrl + url;
	};

	private ExpandableListView listeViewDesProduitsDeLaListeParRayon;

	// code s'exécutant à la création de l'activité
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		// on charge la bonne interface (layout)
		setContentView(R.layout.activity_faire_courses);
		listeViewDesProduitsDeLaListeParRayon = (ExpandableListView) findViewById(R.id.expandableListViewProduitsDansListe);
		boutonCaddy=(Button)findViewById(R.id.buttonPoserDansCaddy);
		boutonAnnuler=(Button)findViewById(R.id.buttonAnnulerAchat);
		//qu'est-ce qu'on fait qd on clique dessus
		boutonCaddy.setOnClickListener(listenerCaddy);
		boutonReporter=(Button)findViewById(R.id.buttonReporterAchat);
		//qu'est-ce qu'on fait qd on clique dessus
		boutonReporter.setOnClickListener(listenerReporter);
		//qu'est-ce qu'on fait qd on clique dessus
		boutonAnnuler.setOnClickListener(listenerAnnuler);
	}

	public void traiterDonneesRecues(String jsonResult) {

		ensRayons.clear();
		try {
			JSONObject jsonResponse = new JSONObject(jsonResult);
			JSONArray jsonMainNode = jsonResponse.optJSONArray("coursesAFaire");

			for (int i = 0; i < jsonMainNode.length(); i++) {
				JSONObject jsonChildNode = jsonMainNode.getJSONObject(i);
				String productName = jsonChildNode.optString("produitLib");
				String productNumber = jsonChildNode.optString("produitId");

				String rayName = jsonChildNode.optString("rayonLib");
				String rayNumber = jsonChildNode.optString("rayonId");

				String listeQte = jsonChildNode.optString("listeQte");

				// IDIDIT on stock ces info qlq part
				ensRayons.addArticle(productNumber, productName, rayNumber,
						rayName, listeQte);
				
			}
		} catch (JSONException e) {
			Toast.makeText(getApplicationContext(), "Error" + e.toString(),
					Toast.LENGTH_SHORT).show();
		}

		// création de l'adapteur pour le choix du rayon qd on fait la liste de
		// course
		AdapterExpandableRayonsProduits monAdapteur = new AdapterExpandableRayonsProduits(
				this, ensRayons);
		monAdapteur.setEnsRayon(ensRayons);
		
		

		try {
			// on associe l'adaptateur à la listView
			listeViewDesProduitsDeLaListeParRayon.setAdapter(monAdapteur);

		} catch (NullPointerException e) {

			Log.i("ListeDeCourse",
					listeViewDesProduitsDeLaListeParRayon.toString());

		}
	}

	//le listener pour supprimer des rayons (clic sur bouton supprimer)
		private OnClickListener listenerCaddy=new OnClickListener()
		{
			@Override
			public void onClick(View v)
			{
				
				Log.i("ListeDeCourse","Supression demand�e");
				int nombreDeRayon = ensRayons.getNbRayon();
				Log.i("ListeDeCourseB",""+nombreDeRayon);
				String adresse=baseUrl+"faireCourse.php?action=Caddy";
				boolean supressionAEffectuer=false;
				for(int i=0;i<nombreDeRayon; i++)
				{
					
					ModelRayonGarni rayon=ensRayons.getRayon(i);
					int nombreArticleParRayon=ensRayons.getRayon(i).getNbArticle();
					Log.i("ListeDeCourseC",""+nombreArticleParRayon);
					
					for(int f=0;f<nombreArticleParRayon; f++)
					{
						
					
					if(rayon.getArticle(f).isSelected())
					{
						String noDuProduit=rayon.getArticle(f).getNo();
						Log.i("ListeDeCourseD",""+noDuProduit);
						adresse+="&tabNoProduit[]="+noDuProduit;
						Log.i("adresse",""+adresse);
						supressionAEffectuer=true;
					}
					}
				}//fin du for
				if(supressionAEffectuer=true)accessWebService(adresse);
					}//fin du onClick
		};//fin du OnClickListener

		private OnClickListener listenerReporter=new OnClickListener()
		{
			@Override
			public void onClick(View v)
			{
				
				Log.i("ListeDeCourse","Supression demandée");
				int nombreDeRayon = ensRayons.getNbRayon();
				Log.i("ListeDeCourseB",""+nombreDeRayon);
				String adresse=baseUrl+"faireCourse.php?action=Reporter";
				boolean supressionAEffectuer=false;
				for(int i=0;i<nombreDeRayon; i++)
				{
					
					ModelRayonGarni rayon=ensRayons.getRayon(i);
					int nombreArticleParRayon=ensRayons.getRayon(i).getNbArticle();
					Log.i("ListeDeCourseC",""+nombreArticleParRayon);
					
					for(int f=0;f<nombreArticleParRayon; f++)
					{
						
					
					if(rayon.getArticle(f).isSelected())
					{
						String noDuProduit=rayon.getArticle(f).getNo();
						Log.i("ListeDeCourseD",""+noDuProduit);
						adresse+="&tabNoProduit[]="+noDuProduit;
						Log.i("adresse",""+adresse);
						supressionAEffectuer=true;
					}
					}
				}//fin du for
				if(supressionAEffectuer=true)accessWebService(adresse);
					}//fin du onClick
		};//fin du OnClickListener
		private OnClickListener listenerAnnuler=new OnClickListener()
		{
			@Override
			public void onClick(View v)
			{
				
				Log.i("ListeDeCourse","Supression demand�");
				int nombreDeRayon = ensRayons.getNbRayon();
				Log.i("ListeDeCourseB",""+nombreDeRayon);
				String adresse=baseUrl+"faireCourse.php?action=Annuler";
				boolean supressionAEffectuer=false;
				for(int i=0;i<nombreDeRayon; i++)
				{
					
					ModelRayonGarni rayon=ensRayons.getRayon(i);
					int nombreArticleParRayon=ensRayons.getRayon(i).getNbArticle();
					Log.i("ListeDeCourseC",""+nombreArticleParRayon);
					
					for(int f=0;f<nombreArticleParRayon; f++)
					{
						
					
					if(rayon.getArticle(f).isSelected())
					{
						String noDuProduit=rayon.getArticle(f).getNo();
						Log.i("ListeDeCourseD",""+noDuProduit);
						adresse+="&tabNoProduit[]="+noDuProduit;
						Log.i("adresse",""+adresse);
						supressionAEffectuer=true;
					}
					}
				}//fin du for
				if(supressionAEffectuer=true)accessWebService(adresse);
					}//fin du onClick
		};//fin du OnClickListener
}
