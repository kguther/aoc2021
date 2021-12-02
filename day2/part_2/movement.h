#ifndef MOVEMENT
#define MOVEMENT

#include "movement_step.h"

class Movement {
 public:
  Movement(){};
  Movement& operator+=(MovementStep const& step);
  int id() const {return depth * horizontal;}
 private:
  int horizontal = 0;
  int depth = 0;
  int aim;
};

Movement read_movement_from_file(std::string filename);

#endif
