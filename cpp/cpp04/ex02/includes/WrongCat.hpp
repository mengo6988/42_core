#pragma once
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

class WrongCat : public WrongAnimal {
protected:
public:
  WrongCat();
  ~WrongCat();

  void makeSound() const;
};

#endif
