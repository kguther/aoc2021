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
	int i = 0;
	while(true){
		++i;
		iterator.iteration();
		if(i==100){
			std::cout << "Total number of flashes after 100 iterations " << grid.n_flashes() << std::endl;
		}
		if(grid.total_power_levevl() == 0){
			break;
		}
	}
	std::cout << "Full flash after " << i << " iterations" << std::endl;

}


