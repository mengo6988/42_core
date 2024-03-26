#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <ctime>
#include <iostream>
#include <string>

class Bureaucrat;
class AForm;

using std::cout;
using std::endl;
using std::ostream;
using std::string;

class RobotomyRequestForm : public AForm {
private:
  string target;
  RobotomyRequestForm();

public:
  RobotomyRequestForm(string target);
  RobotomyRequestForm(const RobotomyRequestForm &other);
  ~RobotomyRequestForm();

  RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

  virtual void execute(Bureaucrat const &executor) const;
  string getTarget() const;
};

ostream &operator<<(ostream &o, const RobotomyRequestForm &f);

#endif
