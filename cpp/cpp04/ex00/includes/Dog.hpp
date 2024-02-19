#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>

class Dog : public Animal {
protected:
public:
  Dog();
  ~Dog();

  void makeSound() const;
};

#endif
