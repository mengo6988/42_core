#include "ClapTrap.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  ClapTrap test("test");
  ClapTrap real("real");

  std::cout << real << std::endl;
  real.attack("test");
  std::cout << real << std::endl;
  std::cout << test << std::endl;
  test.takeDamage(3);
  std::cout << test << std::endl;
  test.beRepaired(2);
  std::cout << test << std::endl;
  return EXIT_SUCCESS;
}
