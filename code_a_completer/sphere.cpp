#include <math.h>
#include "sphere.hpp"


Vecteur3D Sphere::Normale(const Point3D & t) const {
	Vecteur3D res(centre, t);
	res.Normaliser();
	return res;
}


int Sphere::Intersection(const Rayon & r, C_Liste_Intersection & l) {
	Point3D centre = this -> Centre();
	float rayon = this -> SphereRayon();
    Point3D origineRayon = r.Orig();
    Vecteur3D d = r.Vect();

    float b = 2.0*((origineRayon-centre).operator*(d));
	float c = (origineRayon-centre).operator*((origineRayon-centre))-(rayon*rayon);

	float delta = b*b-4*c;

	if(delta<0.0){
        return 0;
	}
	else{
        float Rdelta = sqrt((double) delta);
        float t0 = 0.5*(-b-Rdelta);
        float t1 = 0.5*(-b+Rdelta);
        if(t0 >= 0.0){
            float t = t0;
<<<<<<< HEAD
            l.Ajouter(Intersection3D(t, this, this->Milieu1()));
=======
            l.Ajouter(Intersection3D(t,this,this -> Millieu1()));
>>>>>>> 2d32cf8f78f42a7986d9a119b1538e821a2d5a3e
            return 1;
        }
        if(t1 >= 0.0){
            float t = t1;
<<<<<<< HEAD
			l.Ajouter(Intersection3D(t, this, this->Milieu1()));
=======
            l.Ajouter(Intersection3D(t,this,this -> Millieu1()));
>>>>>>> 2d32cf8f78f42a7986d9a119b1538e821a2d5a3e
            return 1;
        }
	}
	return 0;
}
