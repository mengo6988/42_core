#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>
#include <string>

Cat::Cat() : Animal("Cat") {
  std::cout << "Cat constructor called..." << std::endl;
  try {
    this->brain = new Brain();
  } catch (const std::bad_alloc &e) {
    std::cout << "Memory alloc failed..." << e.what() << std::endl;
  }
}

Cat::~Cat() {
  std::cout << "Cat destructor called..." << std::endl;
  delete this->brain;
}

void Cat::makeSound() const { std::cout << "Meow..." << std::endl; }

Cat::Cat(const Cat &other) {
  std::cout << "Cat Copy constructor called..." << std::endl;
  this->type = other.type;
  this->brain = new Brain(*other.brain);
}
Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat Assignement operator..." << std::endl;
  this->type = other.type;
  if (this->brain) {
    delete brain;
  }
  this->brain = new Brain(*(other.brain));
  return *this;
}

void Cat::think(std::string idea, int i) { this->brain->addIdea(idea, i); }

void Cat::getIdea(int index) {
  std::cout << this->brain->getIdea(index) << std::endl;
}
