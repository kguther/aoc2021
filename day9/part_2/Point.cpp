/*
 * Point.cpp
 *
 *  Created on: Dec 9, 2021
 *      Author: kai
 */

#include "Point.h"

bool operator<(Point const& a, Point const &b) {return a.x() < b.x() || (a.x() == b.x() && a.y() < b.y());}

std::vector<Point> Point::adjacent_points() const{
	std::vector<Point> adjacents(0);
	adjacents.push_back(Point(x()-1,y()));
	adjacents.push_back(Point(x(),y()-1));
	adjacents.push_back(Point(x()+1,y()));
	adjacents.push_back(Point(x(),y()+1));
	return adjacents;
}
