/*
 * IntMap.h
 *
 *  Created on: Dec 15, 2021
 *      Author: kai
 */

#ifndef INTMAP_H_
#define INTMAP_H_

#include "Array.h"
#include "Point.h"

class IntMap {
public:
	IntMap(Array<int> const& map_): map(map_) {};
	IntMap(IntMap const &existing_map);
	IntMap() {};
	virtual ~IntMap() {};
	int value(Point const &x) const {return map[x.x()][x.y()];}
	void set_value(Point const &x, int value) {map[x.x()][x.y()] = value;}
	int size_x() const {return map.size();}
	int size_y() const {return map[0].size();}
private:
	Array<int> map;
};

inline IntMap::IntMap(const IntMap &existing_map) {
	map = Array<int>(existing_map.size_x(), std::vector<int>(existing_map.size_y(), 0));
	for(int i = 0; i < existing_map.size_x(); ++i){
		map[i].assign(existing_map.map[i].begin(), existing_map.map[i].end());
	}
}

#endif /* INTMAP_H_ */
