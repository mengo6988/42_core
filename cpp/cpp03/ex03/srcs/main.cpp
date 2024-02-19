#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  FragTrap def;
  std::cout << std::endl;
  DiamondTrap test("test");
  std::cout << std::endl;
  // FragTrap real("frag");
  // std::cout << std::endl;
  // ScavTrap scav("scav");
  // std::cout << std::endl;
  // DiamondTrap hi;

  std::cout << def << std::endl;
  // std::cout << hi << std::endl;
  // std::cout << scav << std::endl;
  // std::cout << real << std::endl;
  std::cout << test << std::endl;
  std::cout << std::endl;
  test.whoAmI();
  std::cout << std::endl;

  // std::cout << std::endl;
  // real.highFivesGuys();
  // std::cout << std::endl;
  return EXIT_SUCCESS;
}
