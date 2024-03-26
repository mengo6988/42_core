#pragma once

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

struct Data {
  string name;
  int index;
};

class Serializer {
private:
public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t ptr);
};

#endif
