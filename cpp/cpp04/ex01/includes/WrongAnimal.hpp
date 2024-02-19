#pragma once
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
  std::string type;

public:
  WrongAnimal();
  WrongAnimal(std::string type);
  WrongAnimal(const WrongAnimal &other);
  WrongAnimal &operator=(const WrongAnimal &other);
  virtual ~WrongAnimal();

  std::string getType() const;
  virtual void makeSound() const;
  void display(std::ostream &stream) const;
};

std::ostream &operator<<(std::ostream &stream, WrongAnimal const &ani);
#endif
