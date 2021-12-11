/*
 * GridIterator.h
 *
 *  Created on: Dec 11, 2021
 *      Author: kai
 */

#ifndef PART_1_GRIDITERATOR_H_
#define PART_1_GRIDITERATOR_H_

#include "OctoGrid.h"

class GridIterator {
public:
	GridIterator(OctoGrid &grid_): grid(grid_) {};
	virtual ~GridIterator() {};
	void iteration();
private:
	void charge_step();
	void flash_step();
	void decharge_step();
	OctoGrid &grid;
};

#endif /* PART_1_GRIDITERATOR_H_ */
