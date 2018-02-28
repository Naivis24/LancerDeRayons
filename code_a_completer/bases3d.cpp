#include <math.h>
#include "bases3d.hpp"

Point3D Point3D::operator +(const Vecteur3D & v) const {
	Point3D res;

	res.X(X() + v.X());
	res.Y(Y() + v.Y());
	res.Z(Z() + v.Z());

	return res;
}

Point3D Point3D::operator -(const Vecteur3D & v) const {
	Point3D res;

	res.X(X() - v.X());
	res.Y(Y() - v.Y());
	res.Z(Z() - v.Z());

	return res;
}

Vecteur3D Point3D::operator -(const Point3D & p) const {
	Vecteur3D v(p, *this);

	return v;
}


// --------------------------------------------------------------------------

float Vecteur3D::Longueur() const {
	return sqrt((x * x) + (y * y) + (z * z));
}

void Vecteur3D::Normaliser() {
	float lg = Longueur();
	x = x/lg;
	y = y/lg;
	z = z/lg;
}

Vecteur3D Vecteur3D::operator +(const Vecteur3D & v) const {
	Vecteur3D res;

	res.X(X() + v.X());
	res.Y(Y() + v.Y());
	res.Z(Z() + v.Z());

	return res;
}

Vecteur3D Vecteur3D::operator -(const Vecteur3D & v) const {
	Vecteur3D res;

	res.X(X() - v.X());
	res.Y(Y() - v.Y());
	res.Z(Z() - v.Z());

	return res;
}

Vecteur3D Vecteur3D::operator -() const {
	Vecteur3D res;

	res.X(-(X()));
	res.Y(-(Y()));
	res.Z(-(Z()));

	return res;
}

Vecteur3D Vecteur3D::operator *(float m) const {
	Vecteur3D res;

	res.X(m*(X()));
	res.Y(m*(Y()));
	res.Z(m*(Z()));

	return res;
}

float Vecteur3D::operator *(const Vecteur3D & v) const {
	return ((x * v.x) + (y * v.y) + (z * v.z));
}

Vecteur3D Vecteur3D::Cross(const Vecteur3D & v) const {
	Vecteur3D res;

	res.X(Y()*v.Z() - Z()*v.Y());
	res.Y(Z()*v.X() - X()*v.Z());
	res.Z(X()*v.Y() - Y()*v.X());

	return res;
}

Vecteur3D Vecteur3D::Reflechir(const Vecteur3D & n) const { //TODO
	Vecteur3D res = (*this) - (n * (2 * (n * (*this))));

	return res;
}

Vecteur3D Vecteur3D::Refracter(const Vecteur3D & norm, float m1, float m2) const { // TODO
	Vecteur3D res;

    float r;
    float cos1;
    float cos2;

	Vecteur3D rayon = *this;
	Vecteur3D norme = norm;

	rayon.Normaliser();
    norme.Normaliser();

    r = m1/m2;
	cos1 = -norme.operator*(rayon);
    cos2 = sqrt(1-(r*r)*(1-(cos1*cos1)));
    res = (rayon).operator*(r)+norme.operator*(r*cos1-cos2);

	return res;
}
