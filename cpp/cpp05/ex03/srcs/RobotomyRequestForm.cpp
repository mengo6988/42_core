#include "RobotomyRequestForm.hpp"
#include <cstddef>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("default") {}
RobotomyRequestForm::RobotomyRequestForm(string target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm("RobotomyRequestForm", 72, 45), target(other.getTarget()) {}
RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this != &other) {
    target = other.getTarget();
  }
  return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (executor.getGrade() > this->getGradeToExecute())
    throw AForm::GradeTooLowException();
  else if (!this->getSignedState())
    throw AForm::NotSignedException();
  else {
    srand(time(NULL));
    cout << ANSI_BRIGHT_MAGENTA << "*drilling noises*" << ANSI_RESET << endl;
    if (rand() % 2)
      cout << target << " has been robotomized successfully" << endl;
    else
      cout << "Robotomy failed..." << endl;
  }
}

string RobotomyRequestForm::getTarget() const { return target; }

ostream &operator<<(ostream &o, const RobotomyRequestForm &f) {
  string b = f.getSignedState() ? "signed" : "unsigned";

  o << f.getName() << " " << b << " Grade to sign: " << f.getGradeToSign()
    << " Grade to execute " << f.getGradeToExecute();
  return o;
}
