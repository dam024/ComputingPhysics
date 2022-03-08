#include "SpaceUilities.hpp"




Point indicesToPoint(unsigned int i, unsigned int j, double hx,double hy) {
  Point p({hx * i,hy * j});
  return p;
}
double distance(Point a,Point b) {
  return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
}
double norm(Point a) {
	return sqrt(a.x*a.x + a.y*a.y);
}