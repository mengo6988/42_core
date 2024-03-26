#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

using std::ostream;
using std::string;

class Bureaucrat;

class Form {
private:
  const string name;
  bool is_signed;
  const int grade_to_sign;
  const int grade_to_execute;
  Form();

public:
  ~Form();
  Form(const string name, int grade_to_sign, int grade_to_execute);
  Form(const Form &other);
  Form &operator=(const Form &other);

  const string &getName() const;
  bool getSignedState() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  void beSigned(Bureaucrat const &br);

  class AlreadySignedException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Already Signed..."; }
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade too low"; }
  };

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade too high"; }
  };
};

ostream &operator<<(ostream &o, const Form &f);

#endif
