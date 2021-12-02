#include <string>
#include <fstream>
#include "movement.h"
#include "movement_step.h"

Movement read_movement_from_file(std::string filename){
  std::ifstream inputfile(filename);
  std::string line;
  Movement movement;
  while(std::getline(inputfile, line)){
    movement += MovementStep(line);
  }
  inputfile.close();
  return movement;
}

Movement& Movement::operator+=(MovementStep const& step){
  aim += step.get_aim();
  depth += aim * step.get_forward();
  horizontal += step.get_forward();
  return *this;
}
