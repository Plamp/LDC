package com.example.listedecoursedev;
/**
 * 
 * @author Peter Lampson
 * *<ol>
*<li>elle est bien ma classe</li>
*<li> Elle est TROP BIEN!</li>
*</ol>
 * la classe ModelRayon correspond à un rayon dans la base de données
 */
public class ModelProduit {
	//propriétés
	private String qteProduit;
	/**
	 * Le nom du rayon appelé rayonLib dans la table rayon
	 */
	private String nomProduit;
	/**
	 * l'id du rayon appelé rayonId dans la table rayon
	 */
	private String noProduit;
	/**
	 * booléan indiquant si le rayon est sélectionné en vu de la suppression
	 */
	private boolean selected;
	/**
	 * Constructeur de la classe ModelRayon
	 * A la construction on met false dans selected car il n'y a pas de raison de vouloir le supprimer.
	 * @param no
	 * @param nom
	 */
	public ModelProduit(String no,String nom, String qte){
		nomProduit=nom;
	  noProduit=no;
	  qteProduit=qte;
	  selected=false;
	}
	/**
	 * Accesseur en lecture de la propriété nomRayon
	 * @return Le nom du rayon
	 */
	public String getNom() {
	    return nomProduit;
	  }
	//les accesseurs
	  public void setNom(String nom) {
		  nomProduit = nom;
	  }
	  public String getNo() {
		    return noProduit;
		  }

		  public void setNo(String no) {
			  noProduit = no;
		  }
		  public String getQte() {
			    return qteProduit;
			  }

			  public void setQte(String qte) {
				  qteProduit = qte;
			  }
	  public boolean isSelected() {
	    return selected;
	  }

	  public void setSelected(boolean selectionne) {
	    this.selected = selectionne;
	  }

}
