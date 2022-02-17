#pragma once
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
	virtual std::valarray<long double> f(std::valarray<long double> const& y, double t) const = 0;
	virtual void run() = 0;
};