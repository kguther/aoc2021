/*
 * main.cpp
 *
 *  Created on: Dec 19, 2021
 *      Author: kai
 */

#include <iostream>
#include "ScannerView.h"
#include "Mapper.h"


int main(int argc, char *argv[]){
	auto scanners = views_from_file("input");
	Mapper mapper(scanners);
	mapper.build_map();
	std::cout << "Total number of points " << mapper.map_size() << std::endl;
	std::cout << "Maximal scanner distance " << mapper.max_scanner_distance()<< std::endl;
}

