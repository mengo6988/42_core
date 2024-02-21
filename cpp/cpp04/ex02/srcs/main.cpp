#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  std::cout << "dog test----------------------------" << std::endl;
  const Animal *j = new Dog();
  std::cout << "cat test----------------------------" << std::endl;
  const Animal *i = new Cat();
  std::cout << "delete test----------------------------" << std::endl;
  delete j; // should not create a leak
  delete i;

  std::cout << "array test----------------------------" << std::endl;
  const Animal *animals[6] = {new Dog, new Dog, new Dog,
                              new Cat, new Cat, new Cat};
  for (int i = 0; i < 6; i++) {
    delete animals[i];
  }

  std::cout << "copy test----------------------------" << std::endl;
  Cat cat0;

  std::cout << "add idea ----------------------------" << std::endl;
  cat0.think("test1", 0);
  cat0.think("test2", 1);
  cat0.think("test3", 2);
  std::cout << " idea ----------------------------" << std::endl;
  for (int i = 0; i < 3; i++) {
    cat0.getIdea(i);
  }
  Cat cat1 = cat0;
  cat0.think("testtest", 0);
  cat1.think("test other", 1);
  std::cout << " cat 0 idea ----------------------------" << std::endl;
  for (int i = 0; i < 3; i++) {
    cat0.getIdea(i);
  }
  std::cout << "cat 1 idea ----------------------------" << std::endl;
  for (int i = 0; i < 3; i++) {
    cat1.getIdea(i);
  }

  std::cout << "dog deep copy proof ----------------------------" << std::endl;
  Dog dog0;
  Dog dog1 = dog0;
  std::cout << "Dog0: " << &dog0 << " | Dog1 : " << &dog1 << std::endl;
  std::cout << " Dog0 brain: " << dog0.getBrain() << " | Dog1: brain"
            << dog1.getBrain() << std::endl;

  // Animal ani;
  return 0;
}
