#include <string>
#include "movement_step.h"

MovementStep::MovementStep(std::string input){  
  auto delimiter_position = input.find(" ");
  std::string operation = input.substr(0, delimiter_position);
  int length = std::stoi(input.substr(delimiter_position+1));
  if(operation == "forward"){
    delta_forward = length;
  }
  if(operation == "up"){
    delta_aim = -1 * length;
  }
  if(operation == "down"){
    delta_aim = length;
  }
}
