#include "movement.h"
#include <iostream>

int main(int argc, char *argv[]){
  auto total_movement = read_movement_from_file("input");
  std::cout << "Total movement id " << total_movement.id() << std::endl;
}
