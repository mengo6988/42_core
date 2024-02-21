#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
private:
  std::string *ideas;

public:
  Brain();
  ~Brain();

  Brain(Brain const &other);
  Brain &operator=(const Brain &other);
  void addIdea(std::string idea, int index);
  std::string getIdea(int index);
};

#endif
