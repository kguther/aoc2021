/*
 * HeightMap.h
 *
 *  Created on: Dec 9, 2021
 *      Author: kai
 */

#ifndef PART_1_HEIGHTMAP_H_
#define PART_1_HEIGHTMAP_H_

#include <vector>
#include <string>
#include "Point.h"

typedef std::vector<std::vector<int> > Array;


class HeightMap {
public:
	HeightMap(Array const &map_): map(map_) {};
	virtual ~HeightMap() {};
	int height(Point const &x) const {return map[x.x()][x.y()];}
	std::size_t size_x() const {return map.size();}
	std::size_t size_y() const {return map[0].size();}
	std::vector<Point> points() const;
private:
	Array map;
};

HeightMap map_from_file(std::string filename);

#endif /* PART_1_HEIGHTMAP_H_ */
