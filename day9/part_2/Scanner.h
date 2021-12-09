/*
 * Scanner.h
 *
 *  Created on: Dec 9, 2021
 *      Author: kai
 */

#ifndef PART_1_SCANNER_H_
#define PART_1_SCANNER_H_

#include "HeightMap.h"
#include "Point.h"

class Scanner {
public:
	Scanner(HeightMap const &map_): map(map_) {};
	virtual ~Scanner() {};
	std::vector<int> get_basin_sizes() const;
	std::vector<Point> get_low_points() const;
	int largest_basin_sizes() const;
private:
	bool is_low_point(Point const &x) const;
	int risk_level(Point const &x) const;
	std::vector<Point> adjacent_basin_members(Point const &x) const;
	std::vector<Point> basin(Point const &x) const;
	bool on_map(const Point &y) const;

	HeightMap map;
};

#endif /* PART_1_SCANNER_H_ */
