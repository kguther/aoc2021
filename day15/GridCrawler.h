/*
 * GridCrawler.h
 *
 *  Created on: Dec 15, 2021
 *      Author: kai
 */

#ifndef GRIDCRAWLER_H_
#define GRIDCRAWLER_H_

#include "UnvisitedPoints.h"
#include "RiskMap.h"
#include "PathRiskMap.h"

class GridCrawler {
public:
	GridCrawler(RiskMap const &risk_map_);
	virtual ~GridCrawler() {};

	int iterate();
	void perform_iteration();
private:
	Point current, target;
	UnvisitedPoints unvisited_points;
	PathRiskMap path_risks;
};

#endif /* GRIDCRAWLER_H_ */
