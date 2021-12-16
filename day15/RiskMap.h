/*
 * RiskMap.h
 *
 *  Created on: Dec 15, 2021
 *      Author: kai
 */

#ifndef RISKMAP_H_
#define RISKMAP_H_

#include <vector>
#include <string>
#include "IntMap.h"
#include "Point.h"

class RiskMap {
public:
	RiskMap(Array<int> const &map_): map(map_) {};
	RiskMap() {};
	virtual ~RiskMap() {};
	int risk(Point const &x) const {return map.value(x);}
	int path_weight(std::vector<Point> const &path) const;
	int size_x() const {return map.size_x();}
	int size_y() const {return map.size_y();}
	Point target() const {return Point(size_x()-1, size_y()-1);}
	std::vector<Point> points() const;
	bool is_on_map(Point const &x) const {return x.x() >= 0 && x.y() >= 0 && x.x() < size_x() && x.y() < size_y();}
private:
	IntMap map;
};

RiskMap map_from_file(std::string filename);
RiskMap extended_map_from_file(std::string filename);

#endif /* RISKMAP_H_ */
