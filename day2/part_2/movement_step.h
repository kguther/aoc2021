#ifndef MOVEMENT_STEP
#define MOVEMENT_STEP

#include <string>

class MovementStep {
 public:
  MovementStep(std::string input);
  int get_forward() const {return delta_forward;}
  int get_aim() const {return delta_aim;}
 private:
  int delta_forward = 0;
  int delta_aim = 0;
};

#endif
