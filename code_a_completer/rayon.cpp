#include "rayon.hpp"
#include "objet3D.hpp"
#include "lumiere.h"


int Rayon::Intersections(C_Liste_Intersection & li, Liste<Objet3D> & lo) const {
	// Il n'y a pas d'intersection au depart
	li.Vider();

	// Pour chaque objet 3D
	for (lo.Premier(); lo.Courant() != 0; lo.Suivant())
		lo.Courant()->Intersection(*this, li);
	li.Dernier();

	return !(li.Vide());
}

RVB Rayon::Lancer(Liste<Objet3D> & lo, Liste<Lumiere> & ll, int recur) const {
	RVB res;

	C_Liste_Intersection li = C_Liste_Intersection();

	// on calcule toutes les intersections
	bool b = this->Intersections(li, lo);

	// A FAIRE
	if (b == true) {
		// origine et direction sont des vecteurs de R3
		if (recur <= 0) {
			return RVB(0, 0, 0);
		}
		else {
			// TODO : les opérations sur les pointeurs ne marchent pas
			Intersection3D Intersect = *li.Premier();
			/*li.Suivant();
			while (li.Courant() != li.Dernier()) {
				if (Intersect.Dist() < li.Courant()->Dist()) {
					Intersect = *li.Courant();
				}
				*li.Suivant();
			}

			if (Intersect.Dist() < li.Dernier()->Dist()) {
				Intersect = *li.Dernier();
			}*/

			Vecteur3D vect = this->Vect().Reflechir(Intersect.Norm());

			//calcul de l'origine du rayon
			float distance = Intersect.Dist();
			Point3D orgNouveauRayon = this->Orig().operator+((this->Vect().operator*(distance)));

			// la reflexion
			Rayon reflect = Rayon();
			reflect.Orig() = orgNouveauRayon;
			reflect.Vect() = vect;

			// la refraction

			return li.Courant()->Objt()->Couleur();
		}
	}
	else {
		return RVB(0, 0, 0);
	}
}

