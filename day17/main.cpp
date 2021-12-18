/*
 * main.cpp
 *
 *  Created on: Dec 17, 2021
 *      Author: kai
 */

#include <iostream>
#include "TargetArea.h"
#include "ProbeSimulator.h"

int main(int argc, char *argv[]){
	TargetArea target(Point(282, -80), Point(314, -45));
	ProbeSimulator prober(target);
	auto target_info = prober.scan_paths(400);
	std::cout << "Max height possible is " << target_info.max_height << std::endl;
	std::cout << "Number of hitting initial parameters " << target_info.hit_counts << std::endl;
}


