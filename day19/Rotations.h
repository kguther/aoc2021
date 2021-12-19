/*
 * Rotations.h
 *
 *  Created on: Dec 19, 2021
 *      Author: kai
 */

#ifndef ROTATIONS_H_
#define ROTATIONS_H_

#include <vector>
#include "Point.h"

class Rotations {
public:
	Rotations() {};
	virtual ~Rotations() {};
	std::vector<View> view_rotations(View view) const;
};

#endif /* ROTATIONS_H_ */
