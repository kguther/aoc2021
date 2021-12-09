/*
 * Scanner.h
 *
 *  Created on: Dec 9, 2021
 *      Author: kai
 */

#ifndef PART_1_SCANNER_H_
#define PART_1_SCANNER_H_

#include "HeightMap.h"
#include "Point.h"

class Scanner {
public:
	Scanner(HeightMap const &map_): map(map_) {};
	virtual ~Scanner() {};
	int scan_map() const;
private:
	bool is_low_point(Point const &x) const;
	int risk_level(Point const &x) const;
	HeightMap map;
};

#endif /* PART_1_SCANNER_H_ */
