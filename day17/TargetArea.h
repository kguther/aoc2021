/*
 * TargetArea.h
 *
 *  Created on: Dec 17, 2021
 *      Author: kai
 */

#ifndef TARGETAREA_H_
#define TARGETAREA_H_

#include <string>
#include "Point.h"

class TargetArea {
public:
	TargetArea(Point const &lower_left_, Point const &upper_right_): upper_right(upper_right_), lower_left(lower_left_) {};
	virtual ~TargetArea() {};

	bool contains_point(Point const &point) const;
	bool overshot(Point const &point) const;
private:
	Point upper_right;
	Point lower_left;
};

#endif /* TARGETAREA_H_ */
