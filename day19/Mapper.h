/*
 * Mapper.h
 *
 *  Created on: Dec 19, 2021
 *      Author: kai
 */

#ifndef MAPPER_H_
#define MAPPER_H_

#include <vector>
#include <set>
#include "ScannerView.h"

class Mapper {
public:
	Mapper(std::vector<ScannerView> const &scanners_): scanners(scanners_) {};
	virtual ~Mapper() {};
	void build_map();
	int map_size() const;
	int max_scanner_distance() const;
private:
	std::vector<ScannerView> scanners;
	std::vector<Scanner> global_views;
};

#endif /* MAPPER_H_ */
