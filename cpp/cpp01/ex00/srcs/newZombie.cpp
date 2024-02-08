#include "Zombie.hpp"

Zombie *newZombie(std::string name) {
  Zombie *nz = new Zombie;
  nz->set_name(name);
  return nz;
}
