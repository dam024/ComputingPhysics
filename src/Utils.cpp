#include "Utils.hpp"

void writeIntoFile(std::ofstream& out, double number) {
	out.write(reinterpret_cast<const char *>(&number), sizeof(number));
}
double readFile(std::ifstream& in) {
	double val;
	in.read(reinterpret_cast<char *> (&val), sizeof (val));
	return val;
}


