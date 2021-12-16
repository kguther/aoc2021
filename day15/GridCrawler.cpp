/*
 * GridCrawler.cpp
 *
 *  Created on: Dec 15, 2021
 *      Author: kai
 */

#include "GridCrawler.h"

GridCrawler::GridCrawler(RiskMap const &risk_map_): current(0,0), unvisited_points(risk_map_, current), path_risks(risk_map_, unvisited_points, current) {
	target = risk_map_.target();
}

int GridCrawler::iterate(){
	bool target_unvisited = true;
	while(target_unvisited){
		perform_iteration();
		target_unvisited = unvisited_points.is_unvisited(target);
	}
	return path_risks.path_risk(target);
}

void GridCrawler::perform_iteration(){
	path_risks.evaluate_path_risks(current);
	current = path_risks.least_unvisited_risk_point();
	unvisited_points.remove_point(current);
}
