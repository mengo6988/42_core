#include "Zombie.hpp"

void randomChump(std::string name) {
  Zombie rc;
  rc.set_name(name);
  rc.announce();
  return;
}
