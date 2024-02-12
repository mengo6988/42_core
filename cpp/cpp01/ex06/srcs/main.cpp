#include "Harl.hpp"
#include <cstdlib>
#include <iostream>

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << "[ Probably complaining about insignificant problems ]"
              << std::endl;
    return EXIT_SUCCESS;
  }
  Harl test;
  test.complain(av[1]);
  return EXIT_SUCCESS;
}
