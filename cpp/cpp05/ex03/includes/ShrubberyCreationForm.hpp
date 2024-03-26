#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <fstream>
#include <iostream>
#include <string>

class Bureaucrat;
class AForm;

using std::cout;
using std::endl;
using std::ostream;
using std::string;

class ShrubberyCreationForm : public AForm {
private:
  string target;
  ShrubberyCreationForm();

public:
  ShrubberyCreationForm(string target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ~ShrubberyCreationForm();

  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

  virtual void execute(Bureaucrat const &executor) const;
  string getTarget() const;
};

ostream &operator<<(ostream &o, const ShrubberyCreationForm &f);

#endif
