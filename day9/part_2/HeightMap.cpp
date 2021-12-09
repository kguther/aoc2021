/*
 * HeightMap.cpp
 *
 *  Created on: Dec 9, 2021
 *      Author: kai
 */

#include <fstream>
#include <cstdlib>
#include "HeightMap.h"

std::vector<int> line_as_ints(std::string const &string){
	std::vector<int> row(0);
	for(auto x: string){
		row.push_back(atoi(&x));
	}
	return row;
}

std::vector<Point> HeightMap::points() const{
	std::vector<Point> points_of_map(0);
	for(int x=0; x < size_x(); ++x){
		for(int y=0; y < size_y(); ++y){
			points_of_map.push_back(Point(x,y));
		}
	}
	return points_of_map;
}

HeightMap map_from_file(std::string filename){
	std::ifstream inputfile(filename);
	std::string line;
	Array map;
	while(inputfile >> line){
		map.push_back(line_as_ints(line));
	}
	return HeightMap(map);
}
