#include "Form.hpp"

Form::Form()
    : name(""), is_signed(false), grade_to_sign(75), grade_to_execute(75) {}
Form::~Form() {}

Form::Form(const string name, int grade_to_sign, int grade_to_execute)
    : name(name), is_signed(false), grade_to_sign(grade_to_sign),
      grade_to_execute(grade_to_execute) {
  if (grade_to_sign > 150 || grade_to_execute > 150)
    throw Form::GradeTooLowException();
  if (grade_to_sign < 1 || grade_to_execute < 1)
    throw Form::GradeTooHighException();
}

Form::Form(const Form &other)
    : name(other.name), is_signed(false), grade_to_sign(other.grade_to_sign),
      grade_to_execute(other.grade_to_execute) {}

Form &Form::operator=(const Form &other) {
  if (this != &other) {
  }
  return *this;
}

const string &Form::getName() const { return name; }
bool Form::getSignedState() const { return is_signed; }
int Form::getGradeToSign() const { return grade_to_sign; }
int Form::getGradeToExecute() const { return grade_to_execute; }

void Form::beSigned(Bureaucrat const &br) {
  if (br.getGrade() > grade_to_sign)
    throw Form::GradeTooLowException();
  if (is_signed == true)
    throw Form::AlreadySignedException();
  is_signed = true;
}

ostream &operator<<(ostream &o, const Form &f) {
  string b = f.getSignedState() ? "signed" : "unsigned";
  o << f.getName() << ", " << b << ", Grade to sign: " << f.getGradeToSign()
    << ", Grade to execute: " << f.getGradeToExecute();
  return o;
}
