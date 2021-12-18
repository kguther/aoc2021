/*
 * Probe.h
 *
 *  Created on: Dec 17, 2021
 *      Author: kai
 */

#ifndef PROBE_H_
#define PROBE_H_

#include "Point.h"

class Probe {
public:
	Probe(Point const &v_initial): velocity(v_initial), position(0,0) {};
	Point get_position() const {return position;}
	virtual ~Probe() {};

	void move();
private:
	Point velocity;
	Point position;
};

#endif /* PROBE_H_ */
