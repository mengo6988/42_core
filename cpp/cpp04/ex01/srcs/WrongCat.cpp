#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongCat::WrongCat() : WrongAnimal("Cow") {
  std::cout << "WrongCat constructor called..." << std::endl;
}

WrongCat::~WrongCat() { std::cout << "Cat destructor called..." << std::endl; }

void WrongCat::makeSound() const { std::cout << "Wrong Meow..." << std::endl; }
