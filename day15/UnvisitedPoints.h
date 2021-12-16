/*
 * UnvisitedPoints.h
 *
 *  Created on: Dec 15, 2021
 *      Author: kai
 */

#ifndef UNVISITEDPOINTS_H_
#define UNVISITEDPOINTS_H_

#include "RiskMap.h"

class UnvisitedPoints {
public:
	UnvisitedPoints(RiskMap const &risk_map, Point const &initial);
	virtual ~UnvisitedPoints() {};
	void remove_point(Point const &point);
	bool is_unvisited(Point const &point) const;
	std::vector<Point> points() const {return unvisited;}
private:
	std::vector<Point> unvisited;
};

#endif /* UNVISITEDPOINTS_H_ */
