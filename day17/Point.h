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
	Point& operator+=(Point const &other) {x_coord += other.x(); y_coord += other.y(); return *this;}
	Point& operator-=(Point const &other) {*this += Point(-other.x(), -other.y()); return *this;}

	bool has_lower_coordinates(Point const &other) const {return x() <= other.x() && y() <= other.y();}
private:
	int x_coord;
	int y_coord;
};

inline Point operator+(Point a, Point const &b){
	a+=b;
	return a;
}

inline Point operator-(Point a, Point const &b){
	a-=b;
	return a;
}

inline bool operator==(Point const &a, Point const &b){
	return a.x() == b.x() && a.y() == b.y();
}

inline bool operator!=(Point const &a, Point const &b){
	return not (a==b);
}

#endif /* PART_1_POINT_H_ */
