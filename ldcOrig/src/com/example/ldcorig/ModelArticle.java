package com.example.ldcorig;

public class ModelArticle {
	private String nomArticle;
	private String noArticle;
	private String qteArticle;
	private boolean selected;

	public ModelArticle(String no, String nom ,String qte) {
		nomArticle = nom;
		noArticle = no;
		qteArticle = qte;
		selected = false;
	}

	public String getNom() {
		return nomArticle;
	}

	public void setNom(String nom) {
		nomArticle = nom;
	}

	public String getNo() {
		return noArticle;
	}

	public void setNo(String no) {
		noArticle = no;
	}
	
	public String getQte() {
		return qteArticle;
	}

	public void setQte(String qte) {
		qteArticle = qte;
	}

	public boolean isSelected() {
		return selected;
	}

	public void setSelected(boolean selectionne) {
		this.selected = selectionne;
	}

}
