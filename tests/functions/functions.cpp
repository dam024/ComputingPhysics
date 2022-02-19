#include "functions.hpp"
#include <valarray>
#include <cmath>
#include <iostream>
#include <iomanip>

bool verifDouble(long double given,long double reference,long double tolerence) {
	return std::abs(given - reference) < tolerence;
}

void printVal(std::valarray<long double> const& t) {
	for(auto a : t) {
		std::cout << std::setprecision(15) << a << " ";
	}
	std::cout << std::endl;
}