/*
 * HeightMap.h
 *
 *  Created on: Dec 9, 2021
 *      Author: kai
 */

#ifndef PART_1_OCTOGRID_H_
#define PART_1_OCTOGRID_H_

#include <vector>
#include <string>
#include "Point.h"

typedef std::vector<std::vector<int> > Array;

int const DECHARGE_LEVEL = 0;
int const FLASH_LEVEL = 9;
int const POST_FLASH_LEVEL = -50;

class OctoGrid {
public:
	OctoGrid(Array const &map_): grid(map_), flash_count(0) {};
	virtual ~OctoGrid() {};
	int const& power_level(Point const &x) const {return grid[x.x()][x.y()];}
	int& power_level(Point const &x) {return const_cast<int &>(static_cast<OctoGrid const&>(*this).power_level(x));}
	void flash(Point const &x);
	std::size_t size_x() const {return grid.size();}
	std::size_t size_y() const {return grid[0].size();}
	int n_flashes() const {return flash_count;}
	std::vector<Point> points() const;
	int total_power_levevl() const;
private:
	Array grid;
	int flash_count;
	bool on_grid(Point const &x) const;
};

OctoGrid grid_from_file(std::string filename);

#endif /* PART_1_OCTOGRID_H_ */
