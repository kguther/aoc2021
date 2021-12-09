/*
 * Scanner.cpp
 *
 *  Created on: Dec 9, 2021
 *      Author: kai
 */

#include "Scanner.h"

int Scanner::scan_map() const {
	int total_risk_level = 0;
	for(auto x: map.points()){
		if(is_low_point(x)){
			total_risk_level += risk_level(x);
		}
	}
	return total_risk_level;
}

bool Scanner::is_low_point(const Point &x) const {
	auto adjacent_points = x.adjacent_points();
	bool is_low = true;
	for(auto y: adjacent_points){
		if((0 <= y.x() && y.x() < map.size_x()) && (0 <= y.y() && y.y() < map.size_y())){
			if(map.height(x) >= map.height(y)){
				is_low = false;
				break;
			}
		}
	}
	return is_low;
}

int Scanner::risk_level(const Point &x) const {
	return map.height(x) + 1;
}
