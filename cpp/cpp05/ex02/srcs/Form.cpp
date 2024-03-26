#include "Form.hpp"

AForm::AForm()
    : name(""), is_signed(false), grade_to_sign(75), grade_to_execute(75) {}
AForm::~AForm() {}

AForm::AForm(const string name, int grade_to_sign, int grade_to_execute)
    : name(name), is_signed(false), grade_to_sign(grade_to_sign),
      grade_to_execute(grade_to_execute) {
  if (grade_to_sign > 150 || grade_to_execute > 150)
    throw AForm::GradeTooLowException();
  if (grade_to_sign < 1 || grade_to_execute < 1)
    throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &other)
    : name(other.name), is_signed(false), grade_to_sign(other.grade_to_sign),
      grade_to_execute(other.grade_to_execute) {}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other) {
  }
  return *this;
}

const string &AForm::getName() const { return name; }
bool AForm::getSignedState() const { return is_signed; }
int AForm::getGradeToSign() const { return grade_to_sign; }
int AForm::getGradeToExecute() const { return grade_to_execute; }

void AForm::beSigned(Bureaucrat const &br) {
  if (br.getGrade() > grade_to_sign)
    throw AForm::GradeTooLowException();
  if (is_signed == true)
    throw AForm::AlreadySignedException();
  is_signed = true;
}

ostream &operator<<(ostream &o, const AForm &f) {
  string b = f.getSignedState() ? "signed" : "unsigned";
  o << f.getName() << ", " << b << ", Grade to sign: " << f.getGradeToSign()
    << ", Grade to execute: " << f.getGradeToExecute();
  return o;
}
