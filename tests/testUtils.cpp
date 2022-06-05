#include "Utils.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	
	string filename("test.out");
	//Test des fonctions d'encodage et de décodage
	ofstream fTest(filename,std::ofstream::binary);

	double n1(1.543725436725);
	unsigned int n2(1242643);
	long double n3(5432.643272454367245);
	int n4(67382931);
	long int n5(684323650174890650);
	short n6(198);
	writeIntoFile<double>(fTest,n1);
	writeIntoFile<unsigned int>(fTest,n2);
	writeIntoFile<long double>(fTest,n3);
	writeIntoFile<int>(fTest,n4);
	writeIntoFile<long int>(fTest,n5);
	writeIntoFile<short>(fTest,n6);

	fTest.close();

	ifstream iTest(filename,std::ifstream::binary);


	bool isErr(false);
	double g1(readFile<double>(iTest));
	if(g1 != n1)  {
		cerr << "Error reading double : got " << g1 << " expected : " << n1 << endl;
		isErr = true;
	}

	unsigned int g2(readFile<unsigned int>(iTest));
	if(g2 != n2) {
		cerr << "Error reading unsigned int : got " << g1 << " expected : " << n2 << endl;
		isErr = true;
	}

	long double g3(readFile<long double>(iTest));
	if(g3 != n3)  {
		cerr << "Error reading long double : got " << g3 << " expected : " << n3 << endl;
		isErr = true;
	}

	int g4(readFile<int>(iTest));
	if(g4 != n4)  {
		cerr << "Error reading int : got " << g4 << " expected : " << n4 << endl;
		isErr = true;
	}

	long int g5(readFile<long int>(iTest));
	if(g5 != n5)  {
		cerr << "Error reading long int : got " << g5 << " expected : " << n5 << endl;
		isErr = true;
	}

	short g6(readFile<short>(iTest));
	if(g6 != n6)  {
		cerr << "Error reading short : got " << g6 << " expected : " << n6 << endl;
		isErr = true;
	}

	if(isErr) {
		return 1;
	} else {
		cout << "All test succeed !" << endl;
		return 0;
	}
}