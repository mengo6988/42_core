#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  ScavTrap def;
  std::cout << std::endl;
  ClapTrap test("test");
  std::cout << std::endl;
  ScavTrap real("real");
  std::cout << std::endl;

  std::cout << def << std::endl;
  std::cout << real << std::endl;
  real.attack("test");
  std::cout << real << std::endl;
  std::cout << test << std::endl;
  test.takeDamage(3);
  std::cout << test << std::endl;
  test.beRepaired(2);
  std::cout << test << std::endl;
  real.guardGate();
  return EXIT_SUCCESS;
}
