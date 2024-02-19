#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap() : ClapTrap("", 100, 100, 30) {
  std::cout << "Frag default..." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  this->hp = 100;
  this->mp = 100;
  this->attack_dmg = 30;

  std::cout << "Frag named constructor..." << std::endl;
}

FragTrap::~FragTrap() { std::cout << "Frag destructor..." << std::endl; }

FragTrap::FragTrap(const FragTrap &other) {
  std::cout << "Frag copy..." << std::endl;
  operator=(other);
}

void FragTrap::display(std::ostream &stream) const {
  stream << "Name: " << name << ", Hp: " << hp << ", Mp: " << mp
         << ", Attack_dmg: " << attack_dmg << std::endl;
}

void FragTrap::highFivesGuys() { std::cout << "High Fives!!!" << std::endl; }

std::ostream &operator<<(std::ostream &stream, FragTrap const &scav) {
  scav.display(stream);
  return stream;
}
