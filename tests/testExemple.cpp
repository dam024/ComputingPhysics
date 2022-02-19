#include <iostream>
#include <iomanip>
#include "functions.hpp"
#include "NumericalScheme.hpp"
#include "NumericalSimulation.hpp"

using namespace std;

/**
 * Il s'agit d'un test qui permet de montrer comment tester une fonction !! de la librairie !!
 * 
 * Ici, on test Runge-Kutta 4 en adaptatif
 */

class System : public OverTimeSimulation {

public:
	//Test effectué sur l'équation différentielle de l'exo 2 : d(x,y)/dt = (Ω * y,  -Ω * x - g)
	valarray<long double> f(valarray<long double> const& y, double t) const override {

		valarray<long double> ret(valarray<long double>(y.size()));
		double omega(5.0);

		ret[0] = omega * y[1];
		ret[1] = - omega * y[0] - 9.81;

		return ret;
	}

};

int main(int argc, char const *argv[])
{
	unsigned int fail(0);
	//Tolérence pour les erreurs d'arrondi avant que ça devienne une erreur de calcul
	long double tolerence(1e-10);
	System* system(new System());
	
	valarray<long double> stateVector(2);
	stateVector[0] = 0;
	stateVector[1] = 5;
	double t(0.0);
	double dt(100.0);

	NumericalScheme scheme(Scheme::RK4,true,1e-4);
	scheme.step(stateVector,t,dt,system);

	if(!verifDouble(t,dt,tolerence)) {
		cerr << "Time is wrong. Given value was " << setprecision(20) << t << " expected value was " << dt << endl;
		fail++;
	}
	//C'est mieux de faire une boucle ici, mais flemme
	if(!verifDouble(stateVector[0],0.14467862695616821875,tolerence)) {
		cerr << "First component is wrong. Given value was " << setprecision(20) << stateVector[0] << " expected value was " << 0 << endl;
		fail++;
	}
	if(!verifDouble(stateVector[1],4.9407842659560092394,tolerence)) {
		cerr << "Second component is wrong. Given value was " << stateVector[1] << " expected value was " << setprecision(20) << 1 << endl;
		fail++;
	}

	if(fail > 0) {
		cerr << "Report : " << fail << " tests failed" << endl;
		return 1;
	} else {
		cout << "All tests succeed !" << endl;
		return 0;
	}

	delete system;

}