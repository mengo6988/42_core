#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>

class Cat : public Animal {
protected:
public:
  Cat();
  ~Cat();

  void makeSound() const;
};

#endif
