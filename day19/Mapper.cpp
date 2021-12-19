/*
 * Mapper.cpp
 *
 *  Created on: Dec 19, 2021
 *      Author: kai
 */

#include <algorithm>
#include <iostream>
#include "Mapper.h"


void Mapper::build_map() {
	Scanner delta = Scanner(scanners[0], Point());
	std::vector<ScannerView> pool = scanners;
	pool.erase(pool.begin());
	bool shrink_pool = false;
	while(pool.size() > 0){
		if(delta.view.get_view().size() == 0){
			throw;
		}
		global_views.push_back(delta);
		shrink_pool = false;
		for(int j = 0; j < global_views.size(); ++j){
			if(shrink_pool){
				break;
			}
			for(int i = 0; i < pool.size(); ++i){
				delta = global_views[j].view.compare(pool[i]);
				if(delta.view.get_view().size() > 0){
					shrink_pool = true;
					pool.erase(pool.begin() + i);
					break;
				}
			}
		}
	}
	global_views.push_back(delta);
}

int Mapper::map_size() const {
	View global_view;
	for(auto scanner: global_views){
		auto view = scanner.view.get_view();
		std::cout << "Total number of view pts " << view.size() << std::endl;
		for(auto point: view){
			if(global_view.end() == std::find(global_view.begin(), global_view.end(), point)){
				global_view.push_back(point);
			}
		}
	}
	return global_view.size();
}

int Mapper::max_scanner_distance() const {
	int max_distance = 0;
	for(auto scanner_a: global_views){
		for(auto scanner_b: global_views){
			int dist = manhattan_dist(scanner_a.position, scanner_b.position);
			max_distance = std::max(max_distance, dist);
		}
	}
	return max_distance;
}
