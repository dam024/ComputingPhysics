#pragma once
#include <valarray>
//#include "NumericalSimulation.hpp"

class NumericalSimulation;

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
