#include <math.h>

#include "lumiere.h"
#include "couleurRVB.hpp"
#include "objet3D.hpp"


RVB Lumiere_Ambiante::Illumination(const Rayon &, const Intersection3D & i, const Point3D &, Liste<Objet3D> &) const {
	RVB res;

	res = i.Objt()->Ambiante() * couleur;

	return res;
}


RVB Lumiere_Ponctuelle::Illumination(const Rayon & r, const Intersection3D & i, const Point3D & p, Liste<Objet3D> & lo) const {
	RVB res;
    Rayon versLumiere;

    versLumiere.Orig(p);
    Vecteur3D vect = this->Pos().operator-(p);
    versLumiere.Vect(vect);
    versLumiere.Milieu(1);

	C_Liste_Intersection li = C_Liste_Intersection();

	// on calcule toutes les intersections
	bool b = r.Intersections(li, lo);

	if(b == false){
        res = RVB(0,0,0);
	}

	//Lr(P,ωi,ωr) = Kd . Li(P,ωi) . cosθi

    return res;

}
