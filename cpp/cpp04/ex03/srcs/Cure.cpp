#include "Cure.hpp"
#include <iostream>
#include <string>

Cure::Cure() : type("cure") {
  std::cout << "Cure default constructor..." << std::endl;
}

Cure::~Cure() { std::cout << "Cure destructor..." << std::endl; }

Cure::Cure(const Cure &other) : type(other.getType()) {
  std::cout << "Cure copy constructor..." << std::endl;
}

Cure &Cure::operator=(const Cure &other) {
  std::cout << "Cure assignment operator..." << std::endl;
  if (this != &other) {
    this->type = other.getType();
  }
  return *this;
}

Cure *Cure::clone() const {
  Cure *res = new Cure;
  return res;
}

void Cure::use(ICharacter &target) {
  std::string to_name = target.getName();
  std::cout << "* Heals " << to_name << "'s wounds *" << std::endl;
}

std::string const &Cure::getType() const { return this->type; }
