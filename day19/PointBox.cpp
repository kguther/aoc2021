/*
 * PointBox.cpp
 *
 *  Created on: Dec 19, 2021
 *      Author: kai
 */

#include "PointBox.h"

void PointBox::add_point(const Point &point) {
	if(points.size() == 0){
		lower_corner = point;
		upper_corner = point;
	}
	points.push_back(point);
	lower_corner = Point(std::min(lower_corner.x(), point.x()), std::min(lower_corner.y(), point.y()), std::min(lower_corner.z(), point.z()));
	upper_corner = Point(std::max(lower_corner.x(), point.x()), std::max(lower_corner.y(), point.y()), std::max(lower_corner.z(), point.z()));
}

bool PointBox::contains_point(const Point &point) const {
	return lower_corner.has_lower_coordinates(point) && point.has_lower_coordinates(upper_corner);
}
