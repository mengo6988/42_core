#pragma once

#include <exception>
#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::vector;

class Span {
private:
  vector<int> vec;
  unsigned int size;
  Span();

public:
  Span(unsigned int N);
  ~Span();
  Span(const Span &other);
  Span &operator=(const Span &other);

  vector<int> get_vec() const;
  unsigned int get_size() const;

  void addNumber(int num);
  void addNumber(vector<int>::iterator bg, vector<int>::iterator en);

  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;

  class SpanFullException : public std::exception {
    virtual const char *what() const throw() { return "Span is full"; }
  };
  class NotEnoughElementsException : public std::exception {
    virtual const char *what() const throw() { return "Not enough elements"; }
  };
};

ostream &operator<<(ostream &o, const Span &sp);

#endif
