package com.example.ldcorig;

import java.util.ArrayList;
import java.util.List;

import android.util.Log;

public class EnsembleDeRayons {
	private List<ModelRayonGarni> lesRayons;

	public EnsembleDeRayons(){
		lesRayons = new ArrayList<ModelRayonGarni>();
	}
	
	int getNbRayon() {
		return lesRayons.size();
	}

	void add(ModelRayonGarni leRayon) {
		lesRayons.add(leRayon);
	}

	ModelRayonGarni getRayon(int indice) {
		return lesRayons.get(indice);
	}

	ModelRayonGarni getRayonById(String noRayon) {
		// this method return "null" if the "rayon" isn't founded in the list
		//Log.i("ListeDeCourse","return the rayon which is founded.");
		ModelRayonGarni leRayon = null;
		int indiceRayons = 0;

		while (!(indiceRayons == lesRayons.size() || lesRayons
				.get(indiceRayons).getNo().equals(noRayon))) {
			Log.i("ListeDeCourse","In the boucle.");
			indiceRayons++;
		}

		if (!(indiceRayons == lesRayons.size())) {// if it found it
			leRayon = lesRayons.get(indiceRayons);
		}
		return leRayon;
	}

	/**
	 * ajoute un rayon et son article ou ajoute au rayon specifié son article
	 * 
	 * @param no
	 *            numero de l'article
	 * @param libelle
	 *            libelle de l'article
	 * @param noR
	 *            numero du rayon
	 * @param libR
	 *            libelle du rayon
	 * @param qte
	 *            qte A ACHETER
	 */
	public void addArticle(String no, String libelle, String noR, String libR,
			String qte) {

		ModelRayonGarni monRayon = getRayonById(noR);
		ModelArticle monArticle = new ModelArticle(no, libelle, qte);
		Log.i("ListeDeCourse","Heeeeeeeeeeeeeeeeeeey");
		if (monRayon == null) {
			monRayon = new ModelRayonGarni(noR, libR);
			monRayon.add(monArticle);
			lesRayons.add(monRayon);
		} else {
			monRayon.add(new ModelArticle(no, libelle, qte));
		}

	}
	public void clear(){
		lesRayons.clear();
	}
}
