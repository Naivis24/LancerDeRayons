// ce Fichier entier en TODO ?

#include <math.h>
#include "bases3d.hpp"

Point3D Point3D::operator +(const Vecteur3D & v) const {
	Point3D res;

	res.X(this.X() + v.X());
	res.Y(this.Y() + v.Y());
	res.Z(this.Z() + v.Z());

	return res;
}

Point3D Point3D::operator -(const Vecteur3D & v) const {
	Point3D res;

	res.X(this.X() - v.X());
	res.Y(this.Y() - v.Y());
	res.Z(this.Z() - v.Z());

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

	res.X(this.X() + v.X());
	res.Y(this.Y() + v.Y());
	res.Z(this.Z() + v.Z());

	return res;
}

Vecteur3D Vecteur3D::operator -(const Vecteur3D & v) const {
	Vecteur3D res;

	res.X(this.X() - v.X());
	res.Y(this.Y() - v.Y());
	res.Z(this.Z() - v.Z());

	return res;
}

Vecteur3D Vecteur3D::operator -() const {
	Vecteur3D res;

	res.X(-(this.X()));
	res.Y(-(this.Y()));
	res.Z(-(this.Z()));

	return res;
}

Vecteur3D Vecteur3D::operator *(float m) const {
	Vecteur3D res;

	res.X(m*(this.X());
	res.Y(m*(this.Y()));
	res.Z(m*(this.Z()));

	return res;
}

float Vecteur3D::operator *(const Vecteur3D & v) const {
	return ((x * v.x) + (y * v.y) + (z * v.z));
}

Vecteur3D Vecteur3D::Cross(const Vecteur3D & v) const {
	Vecteur3D res;

	// A FAIRE

	return res;
}

Vecteur3D Vecteur3D::Reflechir(const Vecteur3D & n) const { //TODO
	Vecteur3D res = (*this) - (n * (2 * (n * (*this))));

	return res;
}

Vecteur3D Vecteur3D::Refracter(const Vecteur3D & norm, float m1, float m2) const { // TODO
	Vecteur3D res;

	// A FAIRE

	return res;
}
