package com.example.listedecoursedev;
/**
 * 
 * @author Peter Lampson
 * *<ol>
*<li>elle est bien ma classe</li>
*<li> Elle est TROP BIEN!</li>
*</ol>
 * la classe ModelRayon correspond � un rayon dans la base de donn�es
 */
public class ModelRayon {
	//propri�t�s
	/**
	 * Le nom du rayon appel� rayonLib dans la table rayon
	 */
	private String nomRayon;
	/**
	 * l'id du rayon appel� rayonId dans la table rayon
	 */
	private String noRayon;
	/**
	 * bool�an indiquant si le rayon est s�lectionn� en vu de la suppression
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
	 * Accesseur en lecture de la propri�t� nomRayon
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
