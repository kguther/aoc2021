/*
 * main.cpp
 *
 *  Created on: Dec 9, 2021
 *      Author: kai
 */

#include <iostream>
#include "Scanner.h"
#include "HeightMap.h"

int main(int argc, char *argv[]){
	auto map = map_from_file("input");
	Scanner scanner(map);
	std::cout << "Total low point risk value " << scanner.scan_map() << std::endl;
}


