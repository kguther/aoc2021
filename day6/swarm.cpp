/*
 * swarm.cpp
 *
 *  Created on: Dec 7, 2021
 *      Author: kai
 */

#include "swarm.h"
#include <algorithm>
#include <iostream>

int swarm::spawn_cycle = 6;
int swarm::spawn_age = 8;

swarm::swarm(std::vector<int> const &initial_timers) {
	auto max_age = std::max(spawn_age, *std::max_element(initial_timers.begin(), initial_timers.end()));
	age_populations = std::vector<long>(max_age, 0);
	for(auto x: initial_timers){
		++age_populations[x];
	}

}

void swarm::tick() {
	std::vector<long> new_populations(0);
	new_populations.insert(new_populations.begin(), age_populations.begin()+1, age_populations.end());
	if(new_populations.size() <= spawn_age){
		new_populations.resize(spawn_age+1);
	}
	new_populations[spawn_cycle] += age_populations[0];
	new_populations[spawn_age] += age_populations[0];
	age_populations = new_populations;
}


