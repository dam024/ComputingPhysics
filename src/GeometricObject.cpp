#include "GeometricObject.hpp"
#include "SpaceUilities.hpp"
#include <cmath>

bool HalfCircle::isPointContained(unsigned int i, unsigned int j) const {
	Point current(indicesToPoint(i,j,hx,hy));
	return distance(current,center) < r && center.x <= current.x;
}
Rectangle HalfCircle::getRectContainer() const {
	int delta_x(2 * this->r / this->hx + 1);//On met 1 de marge, dû à la transformation de double en int
	int delta_y(2 * this->r / this->hy + 1);
	int centerX(this->center.x/this->hx);
	int centerY(this->center.y/this->hy);
	//std::cout << "Verif : " << hx << " " << hy << " " << center.x << " " << center.y << std::endl;
	//std::cout << "Centers (x,y): " << centerX << " " << centerY << std::endl;
	//std::cout << "deltas (x,y): " << delta_x << " " << delta_y << std::endl;
	int xLeft(centerX - delta_x/2 - 1);
	int xRight(centerX + delta_x/2 + 1);
	int yTop(centerY + delta_y/2 + 1);
	int yBottom(centerY - delta_y/2 - 1);
	//std::cout << "Rectangle : " << xLeft << " " << xRight << " " << yTop << " " << yBottom << std::endl;
	//exit(0);
	return Rectangle({xLeft,xRight,yTop,yBottom});
}




bool Ellipse::isPointContained(unsigned int i, unsigned int j) const {
	Point current(indicesToPoint(i,j,hx,hy));
	double xE(current.x - center.x);
	double yE (current.y - center.y);
	return xE*xE/(rx*rx) + yE*yE/(ry*ry) <= 1;
}
Rectangle Ellipse::getRectContainer() const {
	int delta_x(2 * this->rx / this->hx + 1);//On met 1 de marge, dû à la transformation de double en int
	int delta_y(2 * this->ry / this->hy + 1);
	int centerX(this->center.x/this->hx);
	int centerY(this->center.y/this->hy);

	int xLeft(centerX - delta_x/2 - 1);
	int xRight(centerX + delta_x/2 + 1);
	int yTop(centerY + delta_y/2 + 1);
	int yBottom(centerY - delta_y/2 - 1);

	return Rectangle({xLeft,xRight,yTop,yBottom});
}

