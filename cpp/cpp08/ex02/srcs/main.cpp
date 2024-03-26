#include "MutantStack.hpp"
#include <array>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

using std::array;
using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;

int main() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
std::cout << "top" << std::endl;
  std::cout << mstack.top() << std::endl;
  mstack.pop();
std::cout << "size" << std::endl;
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737); //[...] mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);

  vector<int> vec;
  vec.push_back(5);
  vec.push_back(17);
std::cout << "top" << std::endl;
  std::cout << *(vec.end() -1) << std::endl;
  vec.pop_back();
std::cout << "size" << std::endl;
  std::cout << vec.size() << std::endl;
  vec.push_back(3);
  vec.push_back(5);
  vec.push_back(737); //[...] vec.push(0);
  vector<int>::iterator vit = vec.begin();
  vector<int>::iterator vite = vec.end();
  ++vit;
  --vit;
  while (vit != vite) {
    std::cout << *vit << std::endl;
    ++vit;
  }

  return 0;
}
