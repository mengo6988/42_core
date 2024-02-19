#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  std::cout << meta->getType() << " " << std::endl;
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  std::cout << std::endl;
  std::cout << *meta << std::endl;
  std::cout << *i << std::endl;
  std::cout << *j << std::endl;
  i->makeSound(); // will output the cat sound!
  j->makeSound();
  meta->makeSound();
  delete meta;
  delete j;
  delete i;
  std::cout << "__________________________________________________________"
            << std::endl;
  const WrongAnimal *wmeta = new WrongAnimal();
  // const WrongAnimal *j = new Dog();
  const WrongAnimal *wi = new WrongCat();
  std::cout << wmeta->getType() << " " << std::endl;
  // std::cout << j->getType() << " " << std::endl;
  std::cout << wi->getType() << " " << std::endl;
  std::cout << std::endl;
  std::cout << *wmeta << std::endl;
  std::cout << *wi << std::endl;
  // std::cout << *j << std::endl;
  wi->makeSound(); // will output the cat sound!
  // j->makeSound();
  wmeta->makeSound();
  delete wmeta;
  // delete j;
  delete wi;
  return 0;
}
