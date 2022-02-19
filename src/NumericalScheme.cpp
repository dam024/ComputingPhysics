#include "NumericalScheme.hpp"
#include "NumericalSimulation.hpp"
#include <iostream>



double norm(std::valarray<long double> v) {
	double ret(0);
	for(double i : v) {
		ret += i*i;
	}
	return sqrt(ret);
}

void NumericalScheme::step(std::valarray<long double>& y, double& t, double& dt, NumericalSimulation* numericalScheme) const {



	if(adaptativeStep) {
		
		std::valarray<long double> y1(y);
		scheme->scheme(y1,t,dt,numericalScheme);

		std::valarray<long double> y2(y);
		scheme->scheme(y2,t,dt/2,numericalScheme);
		scheme->scheme(y2,t+dt/2,dt/2,numericalScheme);
		long double d(norm(y2-y1));
		if(d < epsilon) {
			y = y2;
			t += dt;
			dt = dt * pow(epsilon / d,1.0/(scheme->getOrder() + 1.0));
		} else {
			while(d > epsilon) {
				dt = 0.99 * dt * pow(epsilon / d, 1.0/(scheme->getOrder() + 1.0));
				y1 = y;
				scheme->scheme(y1,t,dt,numericalScheme);

				y2 = y;
				scheme->scheme(y2,t,dt/2,numericalScheme);
				scheme->scheme(y2,t+dt/2,dt/2,numericalScheme);

				d = norm(y2-y1);
			}
			y = y2;
			t += dt;
		}
	} else {
		scheme->scheme(y,t,dt,numericalScheme);
		t += dt;
	}
}
