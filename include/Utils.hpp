#pragma once
#include <fstream>

void writeIntoFile(std::ofstream& out, double number);
double readFile(std::ifstream& in);

template<typename T>
void writeIntoFile(std::ofstream& out,T number) {
	out.write(reinterpret_cast<const char *>(&number), sizeof(number));
}
template<typename T>
T readFile(std::ifstream& in) {
	T val;
	in.read(reinterpret_cast<char *> (&val), sizeof (val));
	return val;
}