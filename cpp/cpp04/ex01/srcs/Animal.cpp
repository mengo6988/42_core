#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal() : type("default") {
  std::cout << "Animal default constructor.." << std::endl;
}

Animal::Animal(std::string type) : type(type) {
  std::cout << "Animal named constructor..." << std::endl;
}

Animal::Animal(const Animal &other) {
  std::cout << "Animal copy constructor..." << std::endl;
  operator=(other);
}

Animal &Animal::operator=(const Animal &other) {
  std::cout << "Animal assignment constructor..." << std::endl;
  if (this != &other) {
    this->type = other.type;
  }
  return *this;
}

Animal::~Animal() { std::cout << "Animal destructor..." << std::endl; }

void Animal::display(std::ostream &stream) const { stream << "Type: " << type; }

std::ostream &operator<<(std::ostream &stream, Animal const &ani) {
  ani.display(stream);
  return stream;
}

std::string Animal::getType() const { return this->type; }

void Animal::makeSound() const {
  std::cout << "Default don't make any sound..." << std::endl;
}
