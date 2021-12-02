#include <string>

class Movement {
 public:
  Movement(){};
  Movement(std::string input);
  Movement& operator+=(Movement const& other);
  int get_forward() const {return delta_forward;}
  int get_depth() const {return delta_depth;}
  int id() const {return get_depth() * get_forward();}
 private:
  int delta_forward = 0;
  int delta_depth = 0;
};

Movement operator+(Movement a, Movement const &b); 
Movement read_total_movement_from_file(std::string filename);
