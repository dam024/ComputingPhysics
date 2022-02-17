#pragma once
#include <valarray>
#include <iostream>
#include <memory>
#include "Scheme.hpp"
//#include "NumericalSimulation.hpp"

class NumericalSimulation;

enum Scheme {
	RK4,
	RK2,
	EulerExpl
};

/**
 * This class let you create a numerical simulation to integrate equations of the form dy/dt = f(y,t). Initialize the class by providing a Scheme
 */
class NumericalScheme {
protected:
	SchemeModel* scheme;
	bool adaptativeStep;
	double epsilon;
	//static void RK4(std::valarray<double>& y, double t, double dt,NumericalSimulation* numericalScheme);

public:

	NumericalScheme(Scheme scheme, bool adaptativeStep = false, double epsilon = 0) : adaptativeStep(adaptativeStep), epsilon(epsilon) {
		switch(scheme) {
			case Scheme::RK4:
				{
					this->scheme = (new class RK4());
				}
				break;
			case Scheme::RK2:
				{
					this->scheme = (new class RK2());
				}
				break;
			case Scheme::EulerExpl:
				{
					this->scheme = (new class EulerExpl());
				}
				break;
			default:
				std::cout << "Scheme not implemented " << std::endl;
				break;
		}

		if(epsilon == 0) {
			std::cerr << "No epsilon provided for adaptative time step scheme" << std::endl;
			exit(1);
		}
	}

	~NumericalScheme() {
		delete scheme;
	}
	void step(std::valarray<long double>& y, double& t, double& dt, NumericalSimulation*);

};