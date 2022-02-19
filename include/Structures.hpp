#pragma once
#include <iostream>
#include <valarray>

struct Body {
private:
	double m;//Mass – requiered
	double alpha;
public:
	double radius;//Radius – optional. If no radius, raduis = 0;
	bool isFixed;

	Body(double m, double r, bool isFixed,double alpha = 0) : m(m),radius(r),isFixed(isFixed) {}

	double mass(double t = 0) const {
		return m;// + alpha * t;
	}
	void setMass(double m) {
		this->m = m;
	}
};



void print(std::valarray<long double> t) {
	for(auto a : t) {
		std::cout << std::setprecision(15) << a << " ";
	}
	std::cout << std::endl;
}