#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}

Zombie::~Zombie() {
  std::cout << this->name << " is destroyed..." << std::endl;
}

void Zombie::announce() {
  std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name) { this->name = name; }

std::string Zombie::get_name(void) { return this->name; }
