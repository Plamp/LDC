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
import java.util.List;



import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import org.w3c.dom.Document;

import com.example.listedecourse.R;

public class connexionActivity extends BaseActivity {

	
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		//on charge la bonne interface (layout)
		setContentView(R.layout.activity_connect);
		Log.i("testy","bacon");
	}
	@Override
	String url() {
		// TODO Auto-generated method stub
		return baseUrl + url ;
	}

	@Override
	void traiterDonneesRecues(String result) {
		// TODO Auto-generated method stub
		
	}
};
	