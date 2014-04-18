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
public class ModelRayon {
	//propriétés
	/**
	 * Le nom du rayon appelé rayonLib dans la table rayon
	 */
	private String nomRayon;
	/**
	 * l'id du rayon appelé rayonId dans la table rayon
	 */
	private String noRayon;
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
	public ModelRayon(String no,String nom){
	  nomRayon=nom;
	  noRayon=no;
	  selected=false;
	}
	/**
	 * Accesseur en lecture de la propriété nomRayon
	 * @return Le nom du rayon
	 */
	public String getNom() {
	    return nomRayon;
	  }
	//les accesseurs
	  public void setNom(String nom) {
	    nomRayon = nom;
	  }
	  public String getNo() {
		    return noRayon;
		  }

		  public void setNo(String no) {
		    noRayon = no;
		  }
	  public boolean isSelected() {
	    return selected;
	  }

	  public void setSelected(boolean selectionne) {
	    this.selected = selectionne;
	  }

}
