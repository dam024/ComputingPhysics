#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <valarray>
#include <vector>

//#include "ConfigFile.h"
#include "NumericalSimulation.hpp"
#include "NumericalScheme.hpp"
//#include <ComputingPhysics.hpp>


using namespace std;


class System : public OverTimeSimulation {
private:

	
	void printOut(bool force) override {

		//*outputFile << setprecision(20) << t << " " << dt;
		cout << t << " " << stateVector[0]; //<< " " << dt;

		cout << endl;


	}

	void printParameters() const override {
		cout << "printParameters : " << endl;
		cout << t << " " << nsteps << endl;
	}

	/**
	 * Initialisation en fonction du différent mode du programme
	 * 
	 * Cela permet d'effectuer certains traitements d'initialisation en fonction de la partie de l'exercice que l'on fait
	 * 
	 *
	 */
	void initialization() {
		
		//if(part != '') {

		//}
	}


public:
	/*
	Fonction f(y) pour l'équation dy/dt = f(y). Ici, la fonction ne dépend pas du temps.

	Here we took dy/dt = y/100, which exact solution is y(t) = 1/200*y^2 + y0
	*/
	valarray<long double> f(valarray<long double> const& y, double t) const override {
		valarray<long double> ret(valarray<long double>(y.size()));
		
		ret = y / 100;

		return ret;
	}

	void run() {

		//Sélection du schéma
		NumericalScheme scheme(Scheme::RK4,adaptative,epsilon);
		OverTimeSimulation::run(scheme);
	}

	System(int argc, char* argv[]) {
		/*string inputPath("configuration.in"); //Fichier d'input par défaut
		if(argc > 1) {//On change le fichier d'input
			inputPath = argv[1];
		}

		ConfigFile configFile(inputPath);//initialisation du fichier de config

		for(int i(2); i<argc; ++i) {//Récupération des configurations que l'on passe en paramètre de la requête.
			configFile.process(argv[i]);
		}
		tFin = 			configFile.get<double>("tFin");
		nsteps = 		configFile.get<double>("nsteps");
		adaptative = 	configFile.get<bool>("adaptative");
		sampling = 		configFile.get<int>("sampling");
		part = 			configFile.get<char>("part");
		epsilon =		configFile.get<double>("epsilon",0.0);
		*/
		tFin = 1000;
		nsteps = 1000;
		adaptative = false;
		epsilon = 1e-4;
		stateVector = valarray<long double>(1);
		stateVector[0] = 1;


		initialization();

		//On a terminé de récupérer toutes les valeurs
		dt = tFin / nsteps;

		/*// Ouverture du fichier de sortie
	    outputFile = new ofstream(configFile.get<string>("output").c_str());
	    outputFile->precision(15);
	    
	    parametersFile = new ofstream(configFile.get<string>("parametersFile").c_str());
	    parametersFile->precision(15);*/
	}

	/*~System() {
		outputFile->close();
		delete outputFile;

		parametersFile->close();
		delete parametersFile;
	};*/

};


int main(int argc, char* argv[]) {
	System system(argc, argv);
	system.run();

	cout << "End of simulation." << endl;

	return 0;
}