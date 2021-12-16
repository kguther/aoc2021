/*
 * main.cpp
 *
 *  Created on: Dec 15, 2021
 *      Author: kai
 */

#include <iostream>
#include "RiskMap.h"
#include "GridCrawler.h"

int main(int argv, char *argc[]){
	auto risk_map = map_from_file("input");
	GridCrawler crawler(risk_map);
	int lowest_path_weight = crawler.iterate();
	std::cout << "Least risky path has risk value " << lowest_path_weight << std::endl;
	auto extended_map = extended_map_from_file("input");
	GridCrawler extended_crawler(extended_map);
	lowest_path_weight = extended_crawler.iterate();
	std::cout << "Least risky path on full map has risk value " << lowest_path_weight << std::endl;
}


