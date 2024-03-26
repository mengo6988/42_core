#include "RPN.hpp"
#include <string>

RPN::RPN() {}
RPN::~RPN() {}

RPN::RPN(const RPN &other) { *this = other; }

RPN &RPN::operator=(const RPN &other) {
  if (this != &other) {
    data = other.getData();
  }
  return *this;
}

const stack<int> &RPN::getData() const { return data; }

std::ostream &operator<<(std::ostream &o, const RPN &other) {
  stack<int> temp = other.getData();
  while (!temp.empty()) {
    o << temp.top();
    temp.pop();
  }
  return o;
}

void RPN::calculate(string input) {
  if (input.find_first_not_of("0123456789+-/* ") != string::npos ||
      input.length() == 0) {
    cout << "Error" << endl;
    return;
  }
  std::istringstream iss;
  iss.str(input);
  char delim = ' ';
  for (string str; std::getline(iss, str, delim);) {
    cout << "|" << str << "|" << endl;
  }
  // TODO: split the string done, but now do the rest
}
