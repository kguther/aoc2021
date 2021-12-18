/*
 * ProbeSimulator.h
 *
 *  Created on: Dec 17, 2021
 *      Author: kai
 */

#ifndef PROBESIMULATOR_H_
#define PROBESIMULATOR_H_

#include "TargetArea.h"

struct ProbePathParams{
	int max_height = 0;
	bool hits_target = false;
};

struct TargetInfo{
	int max_height = 0;
	int hit_counts = 0;
};

class ProbeSimulator {
public:
	ProbeSimulator(TargetArea const &target_): target(target_) {};
	virtual ~ProbeSimulator() {};

	TargetInfo scan_paths(int range) const;
	ProbePathParams launch(Point const &v_initial) const;

private:
	TargetArea target;
};

#endif /* PROBESIMULATOR_H_ */
