/*
 * FuelConsumption.cpp
 *
 *  Created on: Dec 7, 2021
 *      Author: kai
 */

#include "FuelConsumption.h"
#include <cmath>
#include <algorithm>

long FuelConsumption::minimal_required_fuel() const{
	auto max_range = *std::max_element(pos.begin(), pos.end());
	auto min_range = *std::min_element(pos.begin(), pos.end());
	long fuel = fuel_required(min_range);
	for(int i=min_range; i<=max_range; ++i){
		fuel = std::min(fuel, fuel_required(i));
	}
	return fuel;
}

long FuelConsumption::fuel_required(long target) const{
	long required = 0l;
	for(auto x: pos){
		required += static_cast<long>(std::abs(x - target));
	}
	return required;
}

