#include "AMateria.hpp"
#include <iostream>
#include <string>

AMateria::AMateria() {
  std::cout << "AMateria default constructor..." << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type) {
  std::cout << "AMateria named constructor..." << std::endl;
}

AMateria::AMateria(const AMateria &other) : type(other.type) {
  std::cout << "AMateria copy constructor..." << std::endl;
}

AMateria::~AMateria() { std::cout << "AMateria destructor..." << std::endl; }

std::string const &AMateria::getType() const { return this->type; }

void AMateria::use(ICharacter &target) {
  std::cout << "Base: \"* shoots an abstraction at " << target.getName()
            << " *\"" << std::endl;
}
