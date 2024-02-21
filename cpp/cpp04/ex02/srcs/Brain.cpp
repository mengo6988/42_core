#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
  std::cout << "Brain constructor..." << std::endl;
  this->ideas = new std::string[100];
}

Brain::~Brain() {
  std::cout << "Brain destructor..." << std::endl;
  delete[] this->ideas;
}

Brain::Brain(const Brain &other) {
  std::cout << "Brain copy constructor..." << std::endl;
  this->ideas = new std::string[100];
  for (int i = 0; i < 100; i++) {
    this->ideas[i] = other.ideas[i];
  }
}
Brain &Brain::operator=(const Brain &other) {
  std::cout << "Brain assignment operator..." << std::endl;
  if (this != &other) {
    //   delete[] this->ideas;
    //   this->ideas = new std::string[100];
    for (int i = 0; i < 100; i++) {
      this->ideas[i] = other.ideas[i];
    }
  }
  return *this;
}

void Brain::addIdea(std::string idea, int index) { this->ideas[index] = idea; }
std::string Brain::getIdea(int index) { return (this->ideas[index]); }
