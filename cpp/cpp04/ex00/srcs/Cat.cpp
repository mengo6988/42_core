#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>
#include <string>

Cat::Cat() : Animal("Cat") {
  std::cout << "Cat constructor called..." << std::endl;
}

Cat::~Cat() { std::cout << "Cat destructor called..." << std::endl; }

void Cat::makeSound() const { std::cout << "Meow..." << std::endl; }
