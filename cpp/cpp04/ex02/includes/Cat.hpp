#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Cat : public Animal {
private:
  Brain *brain;

public:
  Cat();
  ~Cat();
  Cat(const Cat &other);
  Cat &operator=(const Cat &other);

  void makeSound() const;
  void think(std::string idea, int i);
  void getIdea(int index);
};

#endif
