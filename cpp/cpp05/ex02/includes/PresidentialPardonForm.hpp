#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>

class Bureaucrat;
class AForm;

using std::cout;
using std::endl;
using std::ostream;
using std::string;

class PresidentialPardonForm : public AForm {
private:
  string target;
  PresidentialPardonForm();

public:
  PresidentialPardonForm(string target);
  PresidentialPardonForm(const PresidentialPardonForm &other);
  ~PresidentialPardonForm();

  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

  virtual void execute(Bureaucrat const &executor) const;
  string getTarget() const;
};

ostream &operator<<(ostream &o, const PresidentialPardonForm &f);

#endif
