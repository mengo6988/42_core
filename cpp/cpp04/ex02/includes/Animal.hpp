#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
  std::string type;

public:
  Animal();
  Animal(std::string type);
  Animal(const Animal &other);
  Animal &operator=(const Animal &other);
  virtual ~Animal() = 0;

  std::string getType() const;
  virtual void makeSound() const;
  void display(std::ostream &stream) const;
};

std::ostream &operator<<(std::ostream &stream, Animal const &ani);
#endif
