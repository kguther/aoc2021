/*
 * Rotations.cpp
 *
 *  Created on: Dec 19, 2021
 *      Author: kai
 */

#include <algorithm>
#include "Rotations.h"

View view_x_rotation(View const &view);
View view_z_rotation(View const &view);
Point x_rotation(Point const &point);
Point z_rotation(Point const &point);



std::vector<View> Rotations::view_rotations(View view) const {
	std::vector<View> rotated_views;
	for(int cyc = 0; cyc < 2; ++cyc){
		for(int step = 0; step < 3; ++step){
			view = view_x_rotation(view);
			rotated_views.push_back(view);
			for(int turn = 0; turn < 3; ++turn){
				view = view_z_rotation(view);
				rotated_views.push_back(view);
			}
		}
		view = view_x_rotation(view_z_rotation(view_x_rotation(view)));
	}
	return rotated_views;
}

View view_x_rotation(View const &view){
	View rotated_view = view;
	std::for_each(rotated_view.begin(), rotated_view.end(), [](Point &p){p = x_rotation(p);});
	return rotated_view;
}

View view_z_rotation(View const &view){
	View rotated_view = view;
	std::for_each(rotated_view.begin(), rotated_view.end(), [](Point &p){p = z_rotation(p);});
	return rotated_view;
}

Point x_rotation(Point const &point){
	return Point(point.x(), point.z(), -point.y());
}

Point z_rotation(Point const &point){
	return Point(-point.y(), point.x(), point.z());
}
