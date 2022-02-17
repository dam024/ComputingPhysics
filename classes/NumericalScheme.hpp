#pragma once
#include <valarray>
#include <iostream>
#include <memory>

enum Scheme {
	RK4,
	RK2,
	EulerExpl
};



class NumericalSimulation {
public:
	/**
	 * Fonction venant d'une équation de la forme dy/dt = f(y), où y est un vecteur
	 * 
	 * f(y) peut représenter une force, par exemple. Dans ce cas, y contient la vitesse et la position.
	 * 
	 * INPUT : 
	 * 		 - y : vecteur dans l'espace de phase
	 * 		 - t : temps auquel faire l'évaluation
	 * 
	 * OUTPUT : 
	 * 		- Le résulat de la fonction. Le vecteur retourné doit avoir la même taille que y !
	 */
	virtual std::valarray<long double> f(std::valarray<long double> const& y, double t) const = 0;
	virtual void run() = 0;
};


class SchemeModel {
private:
	//Order of convergency
	const unsigned int order;
public:
	SchemeModel(unsigned int order) : order(order) {}
	virtual void scheme(std::valarray<long double>& y,double t,double dt,NumericalSimulation* simulation) = 0;

	virtual ~SchemeModel() {};

	unsigned int getOrder() const {return order;};

};

/**
 * Algorithm of Runge-Kutta of order 4 - implementation
 */
class RK4 : public SchemeModel {
protected:


public:
	RK4() : SchemeModel(4) {}
	void scheme(std::valarray<long double>& y,double t,double dt,NumericalSimulation* simulation) override;

};
/**
 * Algorithm of Runge-Kutta of order 2 - implementation
 */
class RK2 : public SchemeModel {
public:
	RK2() : SchemeModel(2) {}
	void scheme(std::valarray<long double>& y,double t,double dt,NumericalSimulation* simulation) override;
};
/**
 * Algorithm explicit of Euler - implementation
 */
class EulerExpl : public SchemeModel {
public:
	EulerExpl() : SchemeModel(1) {}
	void scheme(std::valarray<long double>& y,double t, double dt, NumericalSimulation* simulation) override;
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