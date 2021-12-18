/*
 * ProbeSimulator.cpp
 *
 *  Created on: Dec 17, 2021
 *      Author: kai
 */

#include "ProbeSimulator.h"
#include "Probe.h"

TargetInfo ProbeSimulator::scan_paths(int range) const {
	TargetInfo info;
	ProbePathParams path;
	for(int v_x = 1; v_x <= range; ++v_x){
		for(int v_y = -range; v_y <=range; ++v_y){
			path = launch(Point(v_x, v_y));
			if(path.hits_target){
				info.hit_counts += 1;
				if(path.max_height > info.max_height){
					info.max_height = path.max_height;
				}
			}
		}
	}

	return info;
}

ProbePathParams ProbeSimulator::launch(const Point &v_initial) const {
	Probe probe(v_initial);
	Point pos;
	bool approaching = true;
	ProbePathParams path;
	while(approaching){
		probe.move();
		pos = probe.get_position();
		path.hits_target = target.contains_point(pos);
		approaching = not(target.overshot(pos) || path.hits_target);
		path.max_height = std::max(pos.y(), path.max_height);
	}
	return path;
}
