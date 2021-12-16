/*
 * DistanceMap.cpp
 *
 *  Created on: Dec 15, 2021
 *      Author: kai
 */

#include <vector>
#include "PathRiskMap.h"

PathRiskMap::PathRiskMap(const RiskMap &risk_map_, UnvisitedPoints const &unvisited_, Point const &initial): risk_map(risk_map_), unvisited(unvisited_) {
	int MAX_WEIGHT = 10 * risk_map.size_x() * risk_map.size_y();
	Array<int >path_risk_values(risk_map.size_x(), std::vector<int>(risk_map.size_y(), MAX_WEIGHT));
	path_risks = IntMap(path_risk_values);
	path_risks.set_value(initial, 0);
}

void PathRiskMap::evaluate_path_risks(const Point &pos) {
	auto adjacents = pos.adjacent_points();
	int path_risk, new_risk;
	for(auto point: adjacents){
		if(unvisited.is_unvisited(point) && risk_map.is_on_map(point)){
			path_risk = path_risks.value(point);
			new_risk = path_risks.value(pos) + risk_map.risk(point);
			if(new_risk < path_risk){
				path_risks.set_value(point, new_risk);
			}
		}
	}
}

Point PathRiskMap::least_unvisited_risk_point() const {
	auto unvisited_points = unvisited.points();
	Point least_risky_point = unvisited_points[0];
	for(auto point: unvisited_points){
		if(path_risks.value(point) < path_risks.value(least_risky_point)){
			least_risky_point = point;
		}
	}
	return least_risky_point;
}
