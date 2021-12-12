/*
 * GridIterator.cpp
 *
 *  Created on: Dec 11, 2021
 *      Author: kai
 */

#include "GridIterator.h"

void GridIterator::iteration() {
	charge_step();
	int n_flashes = grid.n_flashes();
	int delta_flashes = 0;
	do{
		n_flashes = grid.n_flashes();
		flash_step();
		delta_flashes = grid.n_flashes() - n_flashes;
	} while(delta_flashes > 0);
	decharge_step();
}

void GridIterator::charge_step() {
	auto charge_op = [this](Point const &x){++(this->grid.power_level(x));};
	iterate_grid(charge_op);
}

void GridIterator::flash_step() {
	auto flash_op = [this](Point const &x){if(this->grid.power_level(x) > FLASH_LEVEL) this->grid.flash(x);};
	iterate_grid(flash_op);
}


void GridIterator::decharge_step() {
	auto decharge_op = [this](Point const &x){if(this->grid.power_level(x) < DECHARGE_LEVEL) this->grid.power_level(x) = DECHARGE_LEVEL;};
	iterate_grid(decharge_op);
}
