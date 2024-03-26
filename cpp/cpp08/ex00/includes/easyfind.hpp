#pragma once

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

template <typename T> typename T::iterator easyfind(T &container, int to_find) {
  typename T::iterator ptr;

  ptr = std::find(container.begin(), container.end(), to_find);
  if (ptr == container.end())
    throw std::exception();
  else
    return ptr;
}

#endif
