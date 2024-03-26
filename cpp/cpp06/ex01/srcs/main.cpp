#include "Serializer.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
  Data *test = new Data;
  test->name = "hello";
  test->index = 0;

  cout << "name: " << Serializer::deserialize(Serializer::serialize(test))->name
       << endl;
  cout << "indeex: "
       << Serializer::deserialize(Serializer::serialize(test))->index << endl;
  delete test;
  return EXIT_SUCCESS;
}
