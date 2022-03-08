#pragma once

#include <iostream>
#include "SpaceUilities.hpp"


class GeometricObject2D {

protected:
	//Caractéristiques du système
	double hx;
	double hy;
	double Lx;
	double Ly;
	unsigned int Nx;
	unsigned int Ny;

	//Caractéristiques de l'objet

public:
	GeometricObject2D() = default;
	//GeometricObject2D(double Lx,double Ly, unsigned int Nx, unsigned int Ny) : hx(Lx/Nx),hy(Ly/Ny),Lx(Lx),Ly(Ly),Nx(Nx),Ny(Ny) {}
	GeometricObject2D(double hx,double hy) : hx(hx),hy(hy) {}

	virtual ~GeometricObject2D() {}

	///@brief indicate if a point (i,j) of the grid is contained in the object
	virtual bool isPointContained(unsigned int i, unsigned int j) const = 0;
	///@brief Return a rectangle that contains the current object geometrically
	virtual Rectangle getRectContainer() const = 0;
};


class HalfCircle : public GeometricObject2D {

protected:
	double r;
	Point center;

public:
	HalfCircle() = default;
	//HalfCircle(double Lx,double Ly,unsigned int Nx,unsigned int Ny,double r, double x, double y) : GeometricObject2D(Lx,Ly,Nx,Ny),r(r),x(x),y(y) {}
	HalfCircle(double hx,double hy,double r, double x, double y) : GeometricObject2D(hx,hy),r(r),center({x,y}) {}

	
	bool isPointContained(unsigned int i, unsigned int j) const override;
	Rectangle getRectContainer() const override;
};


class Ellipse : public GeometricObject2D {
	

protected:
		double rx, ry;
		Point center;
		
		
public:
	Ellipse() = default;
	Ellipse(double hx, double hy, double rx, double ry, double x,  double y) : GeometricObject2D(hx,hy),rx(rx), ry(ry),center({x,y}) {}
	
	bool isPointContained(unsigned int i, unsigned int j) const override;
	Rectangle getRectContainer() const override;	
	
};


