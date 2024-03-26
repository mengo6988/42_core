#pragma once

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template <typename T> class Array {
private:
  T *arr;
  unsigned int length;

public:
  Array() : arr(new T()), length(0) {}
  Array(unsigned int n) : arr(new T[n]), length(n) {}
  ~Array() { delete[] arr; }

  Array(const Array &other) : arr(nullptr), length(0) { *this = other; }
  Array &operator=(const Array &other) {
    if (this != &other) {
      delete[] arr;
      arr = new T[other.length];
      length = other.length;
      for (unsigned int i = 0; i < other.length; i++)
        arr[i] = other.arr[i];
    }
    return *this;
  }

  unsigned int size() const { return length; }
  T &operator[](unsigned int index) const {
    if (index >= length)
      throw Array::IndexOutOfBoundsException();
    return arr[index];
  }

  class IndexOutOfBoundsException : public std::exception {
    virtual const char *what() const throw() { return "Index out of bounds"; }
  };
};

#endif
