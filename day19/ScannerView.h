/*
 * ScannerView.h
 *
 *  Created on: Dec 19, 2021
 *      Author: kai
 */

#ifndef SCANNERVIEW_H_
#define SCANNERVIEW_H_

#include <vector>
#include <string>
#include "Point.h"

struct Scanner;


class ScannerView {
public:
	ScannerView(View const &beacons_): beacons(beacons_) {};
	virtual ~ScannerView() {};
	Scanner compare(ScannerView const &other) const;
	View get_view() const {return beacons;}
private:
	View beacons;
	Scanner compare_rotated_view(View const &view) const;
	bool compare_single_view(View const &view) const;
};

struct Scanner{
	Scanner(): view(View()) {};
	Scanner(ScannerView const &view_, Point const &position_): view(view_), position(position_) {};
	ScannerView view;
	Point position;
};

std::vector<ScannerView> views_from_file(std::string filename);

#endif /* SCANNERVIEW_H_ */
