/*
 * Point.cpp
 *
 *  Created on: Dec 9, 2021
 *      Author: kai
 */

#include "Point.h"

std::vector<Point> Point::adjacent_points() const{
	std::vector<Point> adjacents(0);
	for(int delta_x = -1; delta_x <= 1; ++delta_x){
		for(int delta_y = -1; delta_y <= 1; ++delta_y){
			if(!(delta_x == 0 && delta_y == 0)){
				adjacents.push_back(Point(x()+delta_x,y()+delta_y));
			}
		}
	}
	return adjacents;
}
