/*
 * Point.h
 *
 *  Created on: Dec 9, 2021
 *      Author: kai
 */

#ifndef PART_1_POINT_H_
#define PART_1_POINT_H_

#include <vector>
#include <algorithm>


class Point {
public:
	Point(): x_coord(0), y_coord(0), z_coord(0) {};
	Point(int x, int y, int z): x_coord(x), y_coord(y), z_coord(z) {};
	virtual ~Point() {};
	int x() const {return x_coord;}
	int y() const {return y_coord;}
	int z() const {return z_coord;}
	Point& operator+=(Point const &other) {x_coord += other.x(); y_coord += other.y(); z_coord += other.z(); return *this;}
	Point& operator-=(Point const &other) {*this += Point(-other.x(), -other.y(), -other.z()); return *this;}

	bool has_lower_coordinates(Point const &other) const {return x() <= other.x() && y() <= other.y() && z() <= other.z();}
private:
	int x_coord;
	int y_coord;
	int z_coord;
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
	return a.x() == b.x() && a.y() == b.y() && a.z() == b.z();
}

inline bool operator!=(Point const &a, Point const &b){
	return not (a==b);
}

inline bool operator<(Point const &a, Point const &b) {return a.has_lower_coordinates(b);}

inline int manhattan_dist(Point const &a, Point const &b) {
	auto delta = a-b;
	return abs(delta.x()) + abs(delta.y()) + abs(delta.z());
}

using View=std::vector<Point>;

#endif /* PART_1_POINT_H_ */
