#include "NumericalSimulation.hpp"
#include "NumericalScheme.hpp"

void OverTimeSimulation::run(NumericalScheme const& scheme) {
	t = 0.0;
	unsigned int nstepsReal(0);
	printOut(true);
	while(t < tFin - 0.5*dt) {
		scheme.step(stateVector,t,dt,this);

		printOut(false);
		nstepsReal++;
	}
	this->nsteps = nstepsReal;
	printOut(true);
	printParameters();
}
