#include "Scheme.hpp"
#include "NumericalSimulation.hpp"

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