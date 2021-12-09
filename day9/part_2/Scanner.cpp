/*
 * Scanner.cpp
 *
 *  Created on: Dec 9, 2021
 *      Author: kai
 */

#include "Scanner.h"
#include <algorithm>
#include <functional>
#include <set>

std::vector<Point> Scanner::get_low_points() const {
	auto points = map.points();
	std::vector<Point> low_points(0);
	for(auto x: points){
		if(is_low_point(x)){
			low_points.push_back(x);
		}
	}
	return low_points;
}

bool Scanner::on_map(const Point &y) const {
	return (0 <= y.x() && y.x() < map.size_x())
			&& (0 <= y.y() && y.y() < map.size_y());
}

bool Scanner::is_low_point(const Point &x) const {
	auto adjacent_points = x.adjacent_points();
	bool is_low = true;
	for(auto y: adjacent_points){
		if (on_map(y)) {
			if(map.height(x) >= map.height(y)){
				is_low = false;
				break;
			}
		}
	}
	return is_low;
}

std::vector<int> Scanner::get_basin_sizes() const {
	auto low_points = get_low_points();
	std::vector<int> basin_sizes;
	for(auto x: low_points){
		int basin_size = basin(x).size();
		basin_sizes.push_back(basin_size);
	}
	return basin_sizes;
}

int Scanner::largest_basin_sizes() const {
	auto basin_sizes = get_basin_sizes();
	std::sort(basin_sizes.begin(), basin_sizes.end(), std::greater<int>());
	return basin_sizes[0] * basin_sizes[1] * basin_sizes[2];
}

int Scanner::risk_level(const Point &x) const {
	return map.height(x) + 1;
}

std::vector<Point> Scanner::adjacent_basin_members(const Point &x) const {
	std::vector<Point> basin_members;
	for(auto y: x.adjacent_points()){
		if(on_map(y)){
			if(map.height(y) < 9){
				basin_members.push_back(y);
			}
		}
	}
	return basin_members;
}

std::vector<Point> Scanner::basin(const Point &x) const {
	std::vector<Point> basin = {x};
	std::set<Point> additions;
	std::vector<Point> adjacent_members;
	do{
		basin.insert(basin.end(), additions.begin(), additions.end());
		additions.clear();
		for(auto y: basin){
			adjacent_members = adjacent_basin_members(y);
			for(auto adjacent: adjacent_members){
				auto contained = std::find(basin.begin(), basin.end(), adjacent);
				if(contained == basin.end()){
					additions.insert(adjacent);
				}
			}
		}
	} while(additions.size() > 0);
	return basin;
}
