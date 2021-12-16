/*
 * RiskMap.cpp
 *
 *  Created on: Dec 15, 2021
 *      Author: kai
 */

#include <fstream>
#include <cstdlib>
#include "RiskMap.h"

int RiskMap::path_weight(const std::vector<Point> &path) const {
	int weight = 0;
	for(auto x: path){
		weight += risk(x);
	}
	return weight - risk(Point(0,0));
}

std::vector<Point> RiskMap::points() const{
	std::vector<Point> points_of_map(0);
	for(int x=0; x < size_x(); ++x){
		for(int y=0; y < size_y(); ++y){
			points_of_map.push_back(Point(x,y));
		}
	}
	return points_of_map;
}

std::vector<int> line_as_ints(std::string const &string){
	std::vector<int> row(0);
	for(auto x: string){
		row.push_back(atoi(&x));
	}
	return row;
}

Array<int> array_from_file(const std::string &filename) {
	std::ifstream inputfile(filename);
	std::string line;
	Array<int> map;
	while (inputfile >> line) {
		map.push_back(line_as_ints(line));
	}
	return map;
}

int shifted_risk(int risk){
	return (risk % 9) + 1;
}

RiskMap map_from_file(std::string filename){
	Array<int> map = array_from_file(filename);
	return RiskMap(map);
}

RiskMap extended_map_from_file(std::string filename){
	Array<int> map = array_from_file(filename);
	int const x_map_size = map.size();
	int const y_map_size = map.size();
	Array<int> extended_map(5*x_map_size, std::vector<int>(5*y_map_size, 0));
	int x_offset, y_offset;
	int x_shifted, y_shifted;
	for(int x_copy = 0; x_copy < 5; ++x_copy){
		y_offset = 0;
		x_offset = x_map_size;
		for(int y_copy = 0; y_copy < 5; ++y_copy){
			auto operation = [&](int x, int y){
				if(x_copy + y_copy == 0){
					extended_map[x][y] = map[x][y];
				}
				else{
					x_shifted= x+x_copy*x_map_size;
					y_shifted = y+y_copy*y_map_size;
					extended_map[x_shifted][y_shifted] = shifted_risk(extended_map[x_shifted-x_offset][y_shifted-y_offset]);
				}
			};

			for(int i = 0; i < map.size(); ++i){
				for(int j = 0; j < map[0].size(); ++j){
					operation(i, j);
				}
			}
			y_offset = y_map_size;
			x_offset = 0;
		}
	}
	return RiskMap(extended_map);
}
