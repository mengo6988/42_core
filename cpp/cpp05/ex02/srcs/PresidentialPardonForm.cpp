#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(string target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) {}
PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm("PresidentialPardonForm", 25, 5), target(other.getTarget()) {}
PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  if (this != &other) {
    target = other.getTarget();
  }
  return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (executor.getGrade() > this->getGradeToExecute())
    throw AForm::GradeTooLowException();
  else if (!this->getSignedState())
    throw AForm::NotSignedException();
  else {
    cout << target << " has been pardoned by Zaphod Beeblebrox" << endl;
  }
}
string PresidentialPardonForm::getTarget() const { return target; }

ostream &operator<<(ostream &o, const PresidentialPardonForm &f) {
  string b = f.getSignedState() ? "signed" : "unsigned";

  o << f.getName() << " " << b << ", Grade to sign: " << f.getGradeToSign()
    << " Grade to execute " << f.getGradeToExecute();
  return o;
}
