#include "Bureaucrat.hpp"

using std::ostream;
using std::string;

Bureaucrat::Bureaucrat() : name(""), grade(150) {}

Bureaucrat::Bureaucrat(const string name, int grade)
    : name(name), grade(grade) {
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.getName()), grade(other.getGrade()) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this == &other)
    return *this;
  grade = other.getGrade();
  return *this;
}

const string &Bureaucrat::getName() const { return name; }
int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::incrementGrade() {
  if (grade <= 1)
    throw Bureaucrat::GradeTooHighException();
  grade--;
}

void Bureaucrat::decrementGrade() {
  if (grade >= 150)
    throw Bureaucrat::GradeTooLowException();
  grade++;
}

ostream &operator<<(ostream &o, const Bureaucrat &br) {
  o << br.getName() << ", bureaucrat grade " << br.getGrade();
  return o;
}
