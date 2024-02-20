#include "Brain.hpp"
#include <iostream>

Brain::Brain() { std::cout << "Brain constructor..." << std::endl; }

Brain::~Brain() { std::cout << "Brain destructor..." << std::endl; }

Brain::Brain(const Brain &other) {
  std::cout << "Brain copy constructor..." << std::endl;
  *this = other;
}
Brain &Brain::operator=(const Brain &other) {
  std::cout << "Brain assignment operator..." << std::endl;
  if (this != &other) {
    for (int i = 0; i < 100; i++) {
      this->ideas[i] = other.ideas[i];
    }
  }
  return *this;
}
