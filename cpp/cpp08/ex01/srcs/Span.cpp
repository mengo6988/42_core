#include "Span.hpp"
#include <algorithm>
#include <iterator>

Span::Span() {}
Span::Span(unsigned int N) : size(N) {}
Span::~Span() {}
Span::Span(const Span &other) { *this = other; }
Span &Span::operator=(const Span &other) {
  if (this != &other) {
    vec = other.get_vec();
    size = other.get_size();
  }
  return *this;
}

vector<int> Span::get_vec() const { return vec; }
unsigned int Span::get_size() const { return size; }

void Span::addNumber(int num) {
  if (vec.size() >= size)
    throw Span::SpanFullException();
  vec.push_back(num);
}
void Span::addNumber(vector<int>::iterator bg, vector<int>::iterator en) {
  if (std::distance(bg, en) + vec.size() > size)
    throw Span::SpanFullException();
  else
    vec.insert(vec.end(), bg, en);
}

unsigned int Span::shortestSpan() const {
  if (vec.size() < 2)
    throw Span::NotEnoughElementsException();
  vector<int>::const_iterator i = vec.begin();
  vector<int>::const_iterator j = i + 1;
  int shortest = abs(*j - *i);
  while (j != vec.end()) {
    shortest = abs(*j - *i) < shortest ? abs(*j - *i) : shortest;
    i++;
    j++;
  }
  return shortest;
}
unsigned int Span::longestSpan() const {
  if (vec.size() < 2)
    throw Span::NotEnoughElementsException();
  vector<int>::const_iterator begin = vec.begin();
  vector<int>::const_iterator end = vec.end();

  return (*std::max_element(begin, end) - *std::min_element(begin, end));
}

ostream &operator<<(ostream &o, const Span &sp) {
  vector<int>::iterator i;
  for (i = sp.get_vec().begin(); i != sp.get_vec().end(); i++)
    o << *i << " ";
  return o;
}
