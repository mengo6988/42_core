
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name) {}
HumanB::~HumanB() {}

void HumanB::setName(std::string name) { this->name = name; }
void HumanB::setWeapon(Weapon &weapon) { this->weapon = &weapon; }
Weapon HumanB::getWeapon() { return *this->weapon; }
std::string HumanB::getName() { return this->name; }

void HumanB::attack() {
  std::cout << this->name << " attacks with their " << this->weapon->getType()
            << std::endl;
}
