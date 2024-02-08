#include "Zombie.hpp"

int main(void) {
  Zombie *nz = newZombie("shawn");
  randomChump("random chump");

  delete (nz);
  return 0;
}
