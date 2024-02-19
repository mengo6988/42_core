#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  // FragTrap def;
  // std::cout << std::endl;
  ScavTrap test("test");
  std::cout << std::endl;
  FragTrap real("real");
  std::cout << std::endl;

  // std::cout << def << std::endl;
  std::cout << real << std::endl;
  std::cout << test << std::endl;
  std::cout << std::endl;
  real.highFivesGuys();
  std::cout << std::endl;
  return EXIT_SUCCESS;
}
