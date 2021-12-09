/*
 * Point.h
 *
 *  Created on: Dec 9, 2021
 *      Author: kai
 */

#ifndef PART_1_POINT_H_
#define PART_1_POINT_H_

#include <vector>

class Point {
public:
	Point(): x_coord(0), y_coord(0) {};
	Point(int x, int y): x_coord(x), y_coord(y) {};
	virtual ~Point() {};
	int x() const {return x_coord;}
	int y() const {return y_coord;}
	std::vector<Point> adjacent_points() const;
	bool operator==(Point const &other) {return other.x() == x() && other.y() == y();}
private:
	int x_coord;
	int y_coord;
};

bool operator<(Point const& a, Point const &b);

#endif /* PART_1_POINT_H_ */
