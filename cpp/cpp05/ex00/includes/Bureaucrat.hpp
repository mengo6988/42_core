#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

using std::ostream;
using std::string;

class Bureaucrat {
private:
  const string name;
  int grade;
  Bureaucrat();

public:
  Bureaucrat(const string name, int grade);
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);

  const string &getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();

  class GradeTooLowException : std::exception {
  public:
    virtual const char *what() const throw() { return "Grade too low"; }
  };

  class GradeTooHighException : std::exception {
  public:
    virtual const char *what() const throw() { return "Grade too high"; }
  };
};

ostream &operator<<(ostream &o, const Bureaucrat &br);

#endif
