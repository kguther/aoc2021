/*
 * HeightMap.cpp
 *
 *  Created on: Dec 9, 2021
 *      Author: kai
 */

#include <fstream>
#include <numeric>
#include <cstdlib>
#include "OctoGrid.h"


std::vector<int> line_as_ints(std::string const &string){
	std::vector<int> row(0);
	for(auto x: string){
		row.push_back(atoi(&x));
	}
	return row;
}

OctoGrid grid_from_file(std::string filename){
	std::ifstream inputfile(filename);
	std::string line;
	Array map;
	while(inputfile >> line){
		map.push_back(line_as_ints(line));
	}
	return OctoGrid(map);
}


std::vector<Point> OctoGrid::points() const{
	std::vector<Point> points_of_map(0);
	for(int x=0; x < size_x(); ++x){
		for(int y=0; y < size_y(); ++y){
			points_of_map.push_back(Point(x,y));
		}
	}
	return points_of_map;
}


void OctoGrid::flash(const Point &x) {
	++flash_count;
	power_level(x) = POST_FLASH_LEVEL;
	for(auto neighbour: x.adjacent_points()){
		if(on_grid(neighbour)){
			++power_level(neighbour);
		}
	}
}

bool OctoGrid::on_grid(const Point &x) const {
	return (0 <= x.x() && x.x() < size_x())
			&& (0 <= x.y() && x.y() < size_y());
}

int OctoGrid::total_power_levevl() const {
	int power = 0;
	for(auto line: grid){
		power += std::accumulate(line.begin(), line.end(), 0);
	}
	return power;
}
