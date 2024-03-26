#pragma once

#include <cstddef>
#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

using std::cout;
using std::endl;

template <typename T> void iter(T *head, size_t len, void (*f)(T &)) {
  for (size_t i = 0; i < len; i++) {
    f(head[i]);
  }
}

template <typename T> void print(T &a) { cout << a << endl; }

#endif
