/*
 * main.cpp
 *
 *  Created on: Dec 9, 2021
 *      Author: kai
 */

#include <iostream>

#include "OctoGrid.h"
#include "GridIterator.h"

int main(int argc, char *argv[]){
	auto grid = grid_from_file("input");
	GridIterator iterator(grid);
	for(int i= 0; i < 100; ++i){
		iterator.iteration();
	}
	std::cout << "Total number of flashes " << grid.n_flashes() << std::endl;
}


