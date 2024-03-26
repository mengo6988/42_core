#include "easyfind.hpp"
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
  vector<int> vec;
  vec.push_back(0);
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  vec.push_back(5);
  vec.push_back(6);
  vec.push_back(7);
  vec.push_back(14);

  try {
    vector<int>::iterator ptr = easyfind(vec, 5);
    cout << "found: " << *ptr << endl;

  } catch (std::exception &e) {
    cout << "not found" << endl;
  }

  try {
    vector<int>::iterator ptr = easyfind(vec, 10);
    cout << "found: " << *ptr << endl;

  } catch (std::exception &e) {
    cout << "not found" << endl;
  }

  array<int, 9> arr = {0, 1, 2, 3, 4, 5, 6, 7, 14};

  try {
    array<int, 9>::iterator ptr = easyfind(arr, 5);
    cout << "found: " << *ptr << endl;

  } catch (std::exception &e) {
    cout << "not found" << endl;
  }

  try {
    array<int, 9>::iterator ptr = easyfind(arr, 10);
    cout << "found: " << *ptr << endl;

  } catch (std::exception &e) {
    cout << "not found" << endl;
  }

  list<int> ls;
  ls.push_back(0);
  ls.push_back(1);
  ls.push_back(2);
  ls.push_back(3);
  ls.push_back(4);
  ls.push_back(5);
  ls.push_back(6);
  ls.push_back(7);
  ls.push_back(14);

  try {
    list<int>::iterator ptr = easyfind(ls, 5);
    cout << "found: " << *ptr << endl;

  } catch (std::exception &e) {
    cout << "not found" << endl;
  }

  try {
    list<int>::iterator ptr = easyfind(ls, 10);
    cout << "found: " << *ptr << endl;

  } catch (std::exception &e) {
    cout << "not found" << endl;
  }
}
