#pragma once
#include <valarray>

class NumericalScheme;

/**
 * @brief A general abstract class to represent a numerical simualtion (integtion of differential equations)
 */
class NumericalSimulation {
protected:
	// MARK: Simulation variables
	//Total number of steps. At the beginning of the simulation, this variable contains the planned number of steps (passed in parameter of the program). At the end of the simulation, this variable contain the number of steps performed.
	unsigned int nsteps;
	//Indicate if we use an adaptative time step scheme
	bool adaptative;
	//Accepeted error in case of adaptative time steps scheme
	double epsilon  = 0;

	// MARK: Physical variables
	///@brief State vector which contains the state of the system
	std::valarray<long double> stateVector;


	/**
	 * @brief A method that let you manage some job at each time stetp
	 * 
	 * @detail This method is supposed to print the state of the system if needed. It can performed other kind of work, since it's called at each time steps. You can override this method. Default implementation does nothing. 
	 * 
	 * @param force Indicate if we need to force printing the state of the system
	 */
	virtual void printOut(bool force) {}
	/**
	 * @brief This method let you perform some extra work at the end of the simulation, like printing some parameters of the simulation
	 * 
	 * @detail Default implementation does nothing
	 */
	virtual void printParameters() const {};
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
	/**
	 * @brief A method that launch the simulation and iterate over the steps
	 */
	virtual void run(NumericalScheme const&) = 0;
};


/**
 * @brief A class which let you create simulations over time, i.e. solve differential equations which have a time variable (or more generally Ordinary Differential Equations)
 * 
 * 
 */
class OverTimeSimulation : public NumericalSimulation {
protected:
	///@brief Time of simulation
	unsigned int tFin;
	///@brief current time in simulation
	double t;
	///@brief intervals of time between two steps
	double dt;
public:

	void run(NumericalScheme const&) override;
};