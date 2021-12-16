/*
 * UnvisitedPoints.cpp
 *
 *  Created on: Dec 15, 2021
 *      Author: kai
 */

#include "UnvisitedPoints.h"

#include <algorithm>

UnvisitedPoints::UnvisitedPoints(RiskMap const &risk_map, Point const &initial) {
	unvisited = risk_map.points();
	remove_point(initial);
}


void UnvisitedPoints::remove_point(const Point &point) {
	auto pos = std::find(unvisited.begin(), unvisited.end(), point);
	unvisited.erase(pos);
}

bool UnvisitedPoints::is_unvisited(const Point &point) const {
	auto pos = std::find(unvisited.begin(), unvisited.end(), point);
	return pos != unvisited.end();
}
