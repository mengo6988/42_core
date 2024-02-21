#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>
#include <new>
#include <string>

Dog::Dog() : Animal("Dog") {
  std::cout << "Dog constructor called..." << std::endl;
  try {
    this->brain = new Brain();
  } catch (const std::bad_alloc &e) {
    std::cout << "Memory alloc failed..." << e.what() << std::endl;
  }
}

Dog::~Dog() {
  std::cout << "Dog destructor called..." << std::endl;
  delete this->brain;
}

void Dog::makeSound() const { std::cout << "Woof..." << std::endl; }

Dog::Dog(const Dog &other) {
  std::cout << "Dog Copy constructor..." << std::endl;
  this->type = other.type;
  this->brain = new Brain(*other.brain);
}
Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog Assignement operator..." << std::endl;
  if (this->brain) {
    delete brain;
  }
  this->type = other.type;
  this->brain = new Brain(*other.brain);
  return *this;
}

Brain *Dog::getBrain() const { return this->brain; }
