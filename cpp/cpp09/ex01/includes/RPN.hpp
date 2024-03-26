#pragma once

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <ostream>
#include <sstream>
#include <stack>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::stack;
using std::string;

class RPN {
private:
  stack<int> data;

public:
  RPN();
  ~RPN();
  RPN(const RPN &other);
  RPN &operator=(const RPN &other);
  void calculate(string input);

  const stack<int> &getData() const;
};

ostream &operator<<(ostream &o, const RPN &other);

#endif
