package com.example.listedecoursedev;
import android.os.Bundle;
import android.util.Log;
import android.widget.CheckBox;
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
	
//quelques propriétés de la classe:

	 private String url = "listeRayons.php";
	 public String url(){return baseUrl+url;};
	 private ListView listeViewDesRayons;
	 private Spinner spinnerRayon;
	 public List<Map<String, String>> listeDesMapsRayon = new ArrayList<Map<String, String>>();
 //code s'exécutant à la création de l'activité
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		//on charge la bonne interface (layout)
		setContentView(R.layout.activity_faire_courses);

	}

	 public void traiterDonneesRecues(String jsonResult){
		 try {
			   JSONObject jsonResponse = new JSONObject(jsonResult);
			   JSONArray jsonMainNode = jsonResponse.optJSONArray("rayonInfos");
			 
			   for (int i = 0; i < jsonMainNode.length(); i++) {
			    JSONObject jsonChildNode = jsonMainNode.getJSONObject(i);
			    String name = jsonChildNode.optString("rayonLib");
			    String number = jsonChildNode.optString("rayonId");
			    listeDesMapsRayon.add(creerMapRayon(name, number));
			   }
			  } catch (JSONException e) {
			   Toast.makeText(getApplicationContext(), "Error" + e.toString(),
			     Toast.LENGTH_SHORT).show();
			  }
			ListView listeDesCourses=(ListView) this.findViewById(R.id.listViewProduits);
			
		 String from[]=new String[] { "rayonId","rayonLib" };	
		  int to[]=new int[] { R.id.itemNumero, R.id.itemLibelle};
		  //création de l'adapteur pour le choix du rayon qd on fait la liste de course
		  SimpleAdapter sARayon = new SimpleAdapter(this,listeDesMapsRayon,R.layout.rayon_layout,new String[] { "rayonLib" },new int[] { R.id.itemLibelle});
		  //création de l'adaptateur pour la liste des rayons dans la layout magasin(gestion des rayons)
		  SimpleAdapter rayonAdapter = new SimpleAdapter(
		    this, //le contexte
		    listeDesMapsRayon, //le tableau des maps des rayons
		    R.layout.rayon_layout,//la layout de chaque rayon
		    from, to);//les noms des colonnes à prendre et les identifiants des widgets de destination
		  try{ 
		  //on associe l'adaptateur à la listView
		  listeViewDesRayons.setAdapter(rayonAdapter);
		  spinnerRayon.setAdapter(sARayon);
		  
		 }
		 catch(NullPointerException e){

			 Log.i("ListeDeCourse",listeDesMapsRayon.toString());
		 
		 }
	 }
	 
	 private HashMap<String, String> creerMapRayon(String name, String number) {
	  HashMap<String, String> mapRayon = new HashMap<String, String>();
	  mapRayon.put("rayonId", number);
	  mapRayon.put("rayonLib", name);
	  return mapRayon;
	 }
}
