#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <ostream>
#include <string>

ScavTrap::ScavTrap() : ClapTrap("", 100, 50, 20) {
  std::cout << "Scav default..." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  this->hp = 100;
  this->mp = 50;
  this->attack_dmg = 20;

  std::cout << "Scav named constructor..." << std::endl;
}

ScavTrap::~ScavTrap() { std::cout << "Scav destructor..." << std::endl; }

ScavTrap::ScavTrap(const ScavTrap &other) {
  std::cout << "Scav copy..." << std::endl;
  operator=(other);
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap is now in gatekeeper mode..." << std::endl;
}

void ScavTrap::attack(const std::string &target) {
  if (mp > 0) {
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
              << attack_dmg << " damage!" << std::endl;
    mp--;
  } else {
    std::cout << "Not enough energy..." << std::endl;
  }
}

void ScavTrap::display(std::ostream &stream) const {
  stream << "Name: " << name << ", Hp: " << hp << ", Mp: " << mp
         << ", Attack_dmg: " << attack_dmg << std::endl;
}

std::ostream &operator<<(std::ostream &stream, ScavTrap const &scav) {
  scav.display(stream);
  return stream;
}
