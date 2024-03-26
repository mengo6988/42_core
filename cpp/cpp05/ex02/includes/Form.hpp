#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

using std::ostream;
using std::string;

class Bureaucrat;

class AForm {
private:
  const string name;
  bool is_signed;
  const int grade_to_sign;
  const int grade_to_execute;
  AForm();

public:
  virtual ~AForm();
  AForm(const string name, int grade_to_sign, int grade_to_execute);
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);

  const string &getName() const;
  bool getSignedState() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  void beSigned(Bureaucrat const &br);
  virtual void execute(Bureaucrat const &executor) const = 0;

  class AlreadySignedException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Already Signed..."; }
  };

  class NotSignedException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Not Signed..."; }
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

ostream &operator<<(ostream &o, const AForm &f);

#endif
