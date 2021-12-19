/*
 * ScannerView.cpp
 *
 *  Created on: Dec 19, 2021
 *      Author: kai
 */

#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "ScannerView.h"
#include "Rotations.h"
#include "PointBox.h"

Scanner ScannerView::compare(const ScannerView &other) const{
	Rotations rotations;
	Scanner match;
	auto rotated_views = rotations.view_rotations(other.beacons);
	for(auto view: rotated_views){
		match = compare_rotated_view(view);
		if(match.view.get_view().size() > 0){
			return match;
		}
	}
	return Scanner(View(), Point());
}

Scanner ScannerView::compare_rotated_view(const View &view) const {
	Point shift;
	View shifted_view;
	for(auto beacon: beacons){
		for(auto x: view){
			shift = beacon - x;
			shifted_view = view;
			std::for_each(shifted_view.begin(), shifted_view.end(), [&](Point &x){x+=shift;});
			if(compare_single_view(shifted_view)){
				std::cout << "Found scanner at position " << shift.x() << ", " << shift.y() << ", " << shift.z() << std::endl;
				return Scanner(shifted_view, shift);
			}
		}
	}
	return Scanner(View(), shift);
}

bool ScannerView::compare_single_view(const View &view) const {
	PointBox matching_box;
	View not_matching;
	for(auto x: view){
		if(std::find(beacons.begin(), beacons.end(), x) != beacons.end()){
			matching_box.add_point(x);
		}
		else{
			not_matching.push_back(x);
		}
	}
	for(auto point: not_matching){
		if(matching_box.contains_point(point)){
			return false;
		}
	}
	for(auto point: beacons){
		if(std::find(view.begin(), view.end(), point) == view.end() and matching_box.contains_point(point)){
			return false;
		}
	}
	// Need at least 12 matches to count as agreeing scanners
	if(matching_box.get_points().size() >= 12){
		return true;
	}
	return false;
}

std::vector<ScannerView> views_from_file(std::string filename) {
	std::ifstream inputfile(filename);
	std::string line;
	std::string buffer;
	std::vector<ScannerView> scanner_views;
	View view;
	while(inputfile >> line){
		if(line.find(",") == std::string::npos){
			if(view.size() > 0){
				scanner_views.push_back(ScannerView(view));
			}
			view = View();
		}
		else{
			std::vector<int> coords;
			std::stringstream stream(line);
			int n;
			char ch;

			while(stream >> n) {
			    if(stream >> ch){
			        coords.push_back(n);
			    }
			    else{
			        coords.push_back(n);
			    }
			}
			view.push_back(Point(coords[0], coords[1], coords[2]));
		}
	}
	scanner_views.push_back(ScannerView(view));
	return scanner_views;
}
