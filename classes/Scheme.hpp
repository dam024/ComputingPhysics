#include <valarray>


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
	virtual std::valarray<double> f(std::valarray<double> const& y, double t) = 0;
};


class SchemeModel {
public:
	virtual void scheme(std::valarray<double>& y,double t,double dt,NumericalSimulation* simulation) = 0;
};

class RK4 : SchemeModel {
public:
	void scheme(std::valarray<double>& y,double t,double dt,NumericalSimulation* simulation) override {

		std::valarray<double> k1 = dt * simulation->f(y,t);
		//print(k1);

		std::valarray<double> k2 = dt * simulation->f(y + 0.5 * k1, t + 0.5 * dt);

		std::valarray<double> k3 = dt * simulation->f(y + 0.5 * k2, t + 0.5 * dt);

		std::valarray<double> k4 = dt * simulation->f(y + k3, t + dt);

		y += 1.0/6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
	}

};