package com.example.listedecoursedev;

import java.util.List;

import com.example.listedecourse.R;

import android.app.Activity;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

public class ProduitAdapter extends ArrayAdapter<ModelProduit> {

	private final List<ModelProduit> list;
	private final Activity context;

	public ProduitAdapter(Activity context, List<ModelProduit> list) {
		super(context, R.layout.produit_layout_checkable, list);
		this.context = context;
		this.list = list;
	}

	static class ViewHolder {
		public TextView textNumero;
		public TextView textLibelle;
		public TextView textQte;
		public CheckBox checkbox;
	}

	@Override
	public View getView(int position, View convertView, ViewGroup parent) {
		View view = null;
		if (convertView == null) {
			LayoutInflater inflator = context.getLayoutInflater();
			view = inflator.inflate(R.layout.rayon_layout_checkable, null);
			final ViewHolder viewHolder = new ViewHolder();
			viewHolder.textNumero = (TextView) view
					.findViewById(R.id.itemNumero);
			viewHolder.textLibelle = (TextView) view
					.findViewById(R.id.itemLibelle);
			viewHolder.textQte = (TextView) view
					.findViewById(R.id.itemQte);
					viewHolder.checkbox = (CheckBox) view
					.findViewById(R.id.itemCheckBox);
			viewHolder.checkbox
					.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {

						@Override
						public void onCheckedChanged(CompoundButton buttonView,
								boolean isChecked) {
							ModelProduit element = (ModelProduit) viewHolder.checkbox
									.getTag();
							element.setSelected(buttonView.isChecked());

						}
					});
			view.setTag(viewHolder);
			viewHolder.checkbox.setTag(list.get(position));
		} else {
			view = convertView;
			((ViewHolder) view.getTag()).checkbox.setTag(list.get(position));
		}
		ViewHolder holder = (ViewHolder) view.getTag();

		holder.textNumero.setText(list.get(position).getNo());
		holder.textLibelle.setText(list.get(position).getNom());
		holder.textQte.setText(list.get(position).getQte());
		holder.checkbox.setChecked(list.get(position).isSelected());
		return view;
	}
}
