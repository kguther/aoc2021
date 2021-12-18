/*
 * TargetArea.cpp
 *
 *  Created on: Dec 17, 2021
 *      Author: kai
 */

#include <fstream>
#include "TargetArea.h"

bool TargetArea::contains_point(Point const &point) const {
	return point.has_lower_coordinates(upper_right) && lower_left.has_lower_coordinates(point);
}

bool TargetArea::overshot(const Point &point) const {
	return point.x() > upper_right.x() || point.y() < lower_left.y();
}
