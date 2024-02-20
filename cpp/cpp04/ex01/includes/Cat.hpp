#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>

class Cat : public Animal {
private:
  Brain *brain;

public:
  Cat();
  ~Cat();

  void makeSound() const;
};

#endif
