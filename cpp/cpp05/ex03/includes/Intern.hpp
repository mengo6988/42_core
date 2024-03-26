#pragma once

#include <string>
#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;
using std::string;

class Intern;

typedef AForm *(Intern::*F)(const string &) const;

class Intern {
private:
  static const string form_list[3];
  static const F form_func[3];

  AForm *ShrubberyCreation(const string &target) const;
  AForm *RobotomyRequest(const string &target) const;
  AForm *PresidentialPardon(const string &target) const;

public:
  Intern();
  ~Intern();
  Intern(const Intern &other);

  Intern &operator=(const Intern &other);
  AForm *makeForm(const string &type, const string &target) const;

  class FormNotFoundException : public std::exception {
    virtual const char *what() const throw() { return "Form not found..."; }
  };
};

#endif
