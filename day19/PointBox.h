/*
 * PointBox.h
 *
 *  Created on: Dec 19, 2021
 *      Author: kai
 */

#ifndef POINTBOX_H_
#define POINTBOX_H_

#include "Point.h"

class PointBox {
public:
	PointBox() {};
	virtual ~PointBox() {};
	View get_points() const {return points;}
	void add_point(Point const &point);
	bool contains_point(Point const &point) const;
private:
	View points;
	Point upper_corner;
	Point lower_corner;
};

#endif /* POINTBOX_H_ */
