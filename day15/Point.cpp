/*
 * Point.cpp
 *
 *  Created on: Dec 9, 2021
 *      Author: kai
 */

#include "Point.h"

std::vector<Point> Point::adjacent_points() const{
	std::vector<Point> adjacents(0);
	adjacents.push_back(Point(x()-1,y()));
	adjacents.push_back(Point(x(),y()-1));
	adjacents.push_back(Point(x()+1,y()));
	adjacents.push_back(Point(x(),y()+1));
	return adjacents;
}
