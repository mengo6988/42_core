#include "Zombie.hpp"

int main(void) {
  int n = 5;
  Zombie *nz = zombieHorde(n, "shawn");

  delete[] nz;
  return 0;
}
