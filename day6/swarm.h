/*
 * swarm.h
 *
 *  Created on: Dec 7, 2021
 *      Author: kai
 */

#ifndef SWARM_H_
#define SWARM_H_

#include <vector>
#include <numeric>

class swarm {
public:
	swarm(std::vector<int> const &initial_timers);
	virtual ~swarm(){};
	void tick();

	int max_age() const {return age_populations.size();}
	long number_of_fish() const {return std::accumulate(age_populations.begin(), age_populations.end(), 0l);}
private:
	std::vector<long> age_populations;
	static int spawn_cycle;
	static int spawn_age;
};

#endif /* SWARM_H_ */
