package com.example.ldcorig;

import java.util.List;

import com.example.listedecourse.R;

import android.app.Activity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseExpandableListAdapter;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.TextView;

public class AdapterExpandableRayonsProduits extends BaseExpandableListAdapter {
	private EnsembleDeRayons lesRayons;
	private final Activity context;

	public AdapterExpandableRayonsProduits(Activity context,
			EnsembleDeRayons lesRayons) {
		this.context = context;
		this.lesRayons = lesRayons;
		lesRayons = new EnsembleDeRayons();
	}

	static class ViewHolder {
		protected TextView textRayNumero;
		protected TextView textRayLibelle;
		protected TextView textProdQte;
		protected TextView textProdNumero;
		protected TextView textProdLibelle;
		protected CheckBox checkbox;
	}

	public void setEnsRayon(EnsembleDeRayons lesJolisRayons) {
		lesRayons = lesJolisRayons;
	}

	@Override
	public int getGroupCount() {
		return lesRayons.getNbRayon();
	}

	@Override
	public int getChildrenCount(int groupPosition) {
		// renvoie le nb d'article du rayon à l'indice "groupPosition"
		ModelRayonGarni leRayonChoisi = lesRayons.getRayon(groupPosition);
		return leRayonChoisi.getNbArticle();
	}

	@Override
	public Object getGroup(int groupPosition) {
		return lesRayons.getRayon(groupPosition);
	}

	@Override
	public Object getChild(int groupPosition, int childPosition) {
		return lesRayons.getRayon(groupPosition).getArticle(childPosition);
	}

	@Override
	public long getGroupId(int groupPosition) {
		return Long.parseLong(lesRayons.getRayon(groupPosition).getNo());
	}

	@Override
	public long getChildId(int groupPosition, int childPosition) {
		return Long.parseLong(lesRayons.getRayon(groupPosition)
				.getArticle(childPosition).getNo());
	}

	@Override
	public boolean hasStableIds() {
		return true;
	}

	@Override
	public View getGroupView(int groupPosition, boolean isExpanded,
			View convertView, ViewGroup parent) {
		View v = convertView;
		if (v == null) {
			LayoutInflater inflator = context.getLayoutInflater();
			v = inflator.inflate(R.layout.rayon_liste_layout_checkable, null);
		}
		TextView rayonName = (TextView) v
				.findViewById(R.id.itemLibelleRayonProduitDsListe);
		TextView rayonNo = (TextView) v
				.findViewById(R.id.itemNumeroRayonProduitDsListe);
	 	String nomRayon = lesRayons.getRayon(groupPosition).getNom();
	 	String noRayon = lesRayons.getRayon(groupPosition).getNo();
		rayonName.setText(nomRayon);
		rayonNo.setText(noRayon);
	 	return v; 
	}
	
	/**************************************************************************/
	/*****************              getChildView            *******************/
	/**************************************************************************/
	
	@Override
	public View getChildView(int groupPosition, int childPosition,
			boolean isLastChild, View convertView, ViewGroup parent) {
		View view = null;
		if (convertView == null) {
			LayoutInflater inflator = context.getLayoutInflater();
			view = inflator.inflate(R.layout.produit_layout_checkable, null);
			final ViewHolder viewHolder = new ViewHolder();
			viewHolder.textProdNumero = (TextView) view
					.findViewById(R.id.itemNumeroProduitDsListe);
			viewHolder.textProdLibelle = (TextView) view
					.findViewById(R.id.itemLibelleProduitDsListe);
			viewHolder.textProdQte = (TextView) view
					.findViewById(R.id.itemQuantite);
			viewHolder.checkbox = (CheckBox) view
					.findViewById(R.id.itemCheckBoxProdDsListe);
			viewHolder.checkbox
					.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {

						@Override
						public void onCheckedChanged(CompoundButton buttonView,
								boolean isChecked) {
							ModelArticle element = (ModelArticle) viewHolder.checkbox.getTag();
							element.setSelected(buttonView.isChecked());
						}
					});
			view.setTag(viewHolder);
			viewHolder.checkbox.setTag(lesRayons.getRayon(groupPosition).getArticle(childPosition));
		} else {
			view = convertView;
			((ViewHolder) view.getTag()).checkbox.setTag(lesRayons
					.getRayon(groupPosition).getArticle(childPosition));
		}
		ViewHolder holder = (ViewHolder) view.getTag();
		holder.textProdLibelle.setText(lesRayons
				.getRayon(groupPosition).getArticle(childPosition).getNom());
		holder.textProdNumero.setText(lesRayons
				.getRayon(groupPosition).getArticle(childPosition).getNo());
		holder.textProdQte.setText(lesRayons.getRayon(groupPosition)
				.getArticle(childPosition).getQte());
		holder.checkbox.setChecked(lesRayons.getRayon(groupPosition).getArticle(childPosition)
				.isSelected());
		return view;
	}
	
/**************************************************************************/
/*****************           isChildSelectable          *******************/
/**************************************************************************/
	
	@Override
	public boolean isChildSelectable(int groupPosition, int childPosition) {
		return true;
	}

}
