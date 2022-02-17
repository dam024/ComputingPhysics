#include "NumericalScheme.hpp"
#include <iostream>



double norm(std::valarray<long double> v) {
	double ret(0);
	for(double i : v) {
		ret += i*i;
	}
	return sqrt(ret);
}

void NumericalScheme::step(std::valarray<long double>& y, double& t, double& dt, NumericalSimulation* numericalScheme) {



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


void RK4::scheme(std::valarray<long double>& y, double t, double dt,NumericalSimulation* numericalScheme) {

	std::valarray<long double> k1 = dt * numericalScheme->f(y,t);

	std::valarray<long double> k2 = dt * numericalScheme->f(y + 0.5 * k1, t + 0.5 * dt);

	std::valarray<long double> k3 = dt * numericalScheme->f(y + 0.5 * k2, t + 0.5 * dt);

	std::valarray<long double> k4 = dt * numericalScheme->f(y + k3, t + dt);

	y += 1.0/6.0 * (k1 + 2 * k2 + 2 * k3 + k4);

}

void RK2::scheme(std::valarray<long double>& y, double t, double dt,NumericalSimulation* numericalScheme) {
	
	std::valarray<long double> k1 = dt * numericalScheme->f(y,t);

	std::valarray<long double> k2 = dt * numericalScheme->f(y + 0.5*k1,t + 0.5 * dt);

	y += k2;
}

void EulerExpl::scheme(std::valarray<long double>& y, double t, double dt,NumericalSimulation* numericalScheme) {
	y += numericalScheme->f(y,t) * dt;
}