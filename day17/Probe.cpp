/*
 * Probe.cpp
 *
 *  Created on: Dec 17, 2021
 *      Author: kai
 */

#include "Probe.h"

void Probe::move() {
	position += velocity;
	int delta_x_velocity = 0;
	if(velocity.x() > 0){
		delta_x_velocity = -1;
	}
	if(velocity.x() < 0){
		delta_x_velocity = 1;
	}
	Point delta_velocity(delta_x_velocity, -1);
	velocity += delta_velocity;
}
