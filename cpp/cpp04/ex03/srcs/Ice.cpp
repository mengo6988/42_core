#include "Ice.hpp"
#include <iostream>
#include <string>

Ice::Ice() : type("ice") {
  std::cout << "Ice default constructor..." << std::endl;
  // std::cout << this->type << std::endl;
}

Ice::~Ice() { std::cout << "Ice destructor..." << std::endl; }

Ice::Ice(const Ice &other) : type(other.getType()) {
  std::cout << "Ice copy constructor..." << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
  std::cout << "Ice assignment operator..." << std::endl;
  if (this != &other) {
    this->type = other.getType();
  }
  return *this;
}

Ice *Ice::clone() const {
  Ice *res = new Ice;
  return res;
}

void Ice::use(ICharacter &target) {
  std::string to_name = target.getName();
  std::cout << "* Shoots an ice bolt at " << to_name << " *" << std::endl;
}

std::string const &Ice::getType() const { return this->type; }
