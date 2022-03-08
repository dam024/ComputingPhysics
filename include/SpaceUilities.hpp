#pragma  once
#include <cmath>

struct Point {
  double x;
  double y;
};
struct Rectangle {
	int xLeft;
	int xRight;
	int yTop;
	int yBottom;
};


Point indicesToPoint(unsigned int i, unsigned int j,double hx,double hy);
double distance(Point a,Point b);
double norm(Point a);



