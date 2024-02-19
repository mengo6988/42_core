#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal() : type("default") {
  std::cout << "WrongAnimal default constructor.." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
  std::cout << "WrongAnimal named constructor..." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
  std::cout << "WrongAnimal copy constructor..." << std::endl;
  operator=(other);
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  std::cout << "WrongAnimal assignment constructor..." << std::endl;
  if (this != &other) {
    this->type = other.type;
  }
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor..." << std::endl;
}

void WrongAnimal::display(std::ostream &stream) const {
  stream << "Type: " << type;
}

std::ostream &operator<<(std::ostream &stream, WrongAnimal const &ani) {
  ani.display(stream);
  return stream;
}

std::string WrongAnimal::getType() const { return this->type; }

void WrongAnimal::makeSound() const {
  std::cout << "Wrong Animal sound..." << std::endl;
}
