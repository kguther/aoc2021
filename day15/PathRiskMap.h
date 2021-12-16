/*
 * DistanceMap.h
 *
 *  Created on: Dec 15, 2021
 *      Author: kai
 */

#ifndef PATHRISKMAP_H_
#define PATHRISKMAP_H_

#include "RiskMap.h"
#include "UnvisitedPoints.h"

class PathRiskMap {
public:
	PathRiskMap(RiskMap const &risk_map_, UnvisitedPoints const &unvisited_, Point const &initial);
	virtual ~PathRiskMap() {};
	int path_risk(Point const &x) const {return path_risks.value(x);}
	void set_path_risk(Point const &x, int value) {path_risks.set_value(x, value);}
	void evaluate_path_risks(Point const &pos);
	Point least_unvisited_risk_point() const;
private:
	RiskMap risk_map;
	IntMap path_risks;
	UnvisitedPoints const& unvisited;
};

#endif /* PATHRISKMAP_H_ */
