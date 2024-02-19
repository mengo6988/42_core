#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
private:
  std::string ideas[100];

public:
  Brain();
  ~Brain();

  void makeSound() const;
};

#endif
