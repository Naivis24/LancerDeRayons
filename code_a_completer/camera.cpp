#include "camera.hpp"
#include "bases3d.hpp"
#include "pixelmap.hpp"
#include "rayon.hpp"
#include "sphere.hpp"
#include <stdio.h>

void Camera::Haut(const Vecteur3D & h) {

	haut = h - (dir * (dir * h));
	if (!haut.Nul())
		haut.Normaliser();
}

void Camera::Calculer_image(Pixelmap & pm, Liste<Objet3D> & lo, Liste<Lumiere> & ll, int complexite) const {
	// centre de la camera
	Point3D centre = this->Centre();

	// direction de la camera
	Vecteur3D direction = this->Dir();

	//distance focale
	float distance = this->Dist();

	// le point d'où partent tout les rayons: centre - distance focale
	Point3D origine = centre.operator-(direction.operator*(distance));

	RVB rvb;
	
	// definir les 2 vecteurs de la base de la cam
	Vecteur3D x1 = this->Dir();
	// produit vectoriel de x1 et x2 =0 et produit vectoriel de x1 et direction = 0
	Vecteur3D x2 = this->Haut();

	Vecteur3D x3 = x1.Cross(x2);

	// tous les pixels
	// soit i l'axe des y
	for (int i = -(pm.Hauteur()/2); i < pm.Hauteur()/2; i++) {
		// soit j l'axe des x
		for (int j = -(pm.Largeur()/2); j < pm.Largeur()/2; j++) {
			Point3D pixel = centre.operator+(x2.operator*(i));
			pixel = pixel.operator+(x3.operator*(j));
			// le vecteur du rayon lancer
			Vecteur3D vecteur = origine.operator+(pixel);

			Rayon rayon;
			rayon.Orig(origine);
			rayon.Vect(vecteur);
			rayon.Milieu();

			rvb = rayon.Lancer(lo, ll, 5);

			pm.Map(j + (pm.Largeur() / 2), i + (pm.Hauteur() / 2), rvb);
		}
	}
}
