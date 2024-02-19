#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <ostream>
#include <string>

DiamondTrap::DiamondTrap() : FragTrap(""), ScavTrap("") {
  std::cout << "Diamond default..." << std::endl;
  this->name = "";
  this->ClapTrap::name = "_clap_name";
  FragTrap::hp = 100;
  ScavTrap::mp = 50;
  FragTrap::attack_dmg = 30;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name) {
  std::cout << "Diamond default..." << std::endl;

  this->name = name;
  this->ClapTrap::name = name + "_clap_name";

  FragTrap::hp = 100;
  ScavTrap::mp = 50;
  FragTrap::attack_dmg = 30;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "Diamond destructor..." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) {
  std::cout << "Diamond copy..." << std::endl;
  operator=(other);
}

void DiamondTrap::whoAmI() {
  std::cout << "DiamondTrap name: " << this->name
            << ", ClapTrap name: " << ClapTrap::name << std::endl;
}

void DiamondTrap::display(std::ostream &stream) const {
  stream << "Name: " << this->name << ", Hp: " << hp << ", Mp: " << mp
         << ", Attack_dmg: " << attack_dmg << std::endl;
}

std::ostream &operator<<(std::ostream &stream, DiamondTrap const &scav) {
  scav.display(stream);
  return stream;
}
