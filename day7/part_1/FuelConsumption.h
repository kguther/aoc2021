/*
 * FuelConsumption.h
 *
 *  Created on: Dec 7, 2021
 *      Author: kai
 */

#ifndef PART_1_FUELCONSUMPTION_H_
#define PART_1_FUELCONSUMPTION_H_

#include <vector>

class FuelConsumption {
public:
	FuelConsumption(std::vector<int> pos_): pos(pos_){};
	virtual ~FuelConsumption() {};

	long minimal_required_fuel() const;
private:
	std::vector<int> pos;

	long fuel_required(long target) const;
};

#endif /* PART_1_FUELCONSUMPTION_H_ */
