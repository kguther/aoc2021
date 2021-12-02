#include <string>
#include <fstream>
#include "movement.h"

Movement read_total_movement_from_file(std::string filename){
  std::ifstream inputfile(filename);
  std::string line;
  Movement movement;
  while(std::getline(inputfile, line)){
    movement += Movement(line);
  }
  inputfile.close();
  return movement;
}

Movement::Movement(std::string input){  
  auto delimiter_position = input.find(" ");
  std::string operation = input.substr(0, delimiter_position);
  int length = std::stoi(input.substr(delimiter_position+1));
  if(operation == "forward"){
    delta_forward = length;
  }
  if(operation == "up"){
    delta_depth = -1 * length;
  }
  if(operation == "down"){
    delta_depth = length;
  }
}

Movement& Movement::operator+=(Movement const& other){
  delta_forward += other.delta_forward;
  delta_depth += other.delta_depth;
  return *this;
}

Movement operator+(Movement a, Movement const &b){
  return a+=b;
}
