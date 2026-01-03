#include "Form.hpp"

Form::Form()
	: name("DefaultForm"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
	: name(other.name), isSigned(other.isSigned),
    gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form& Form::operator=(const Form& other) {
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

Form::~Form() {}

const std::string& Form::getName() const {
	return name; }

bool Form::get_Sign() const {
	return isSigned; }

int Form::getGradeToSign() const {
	return gradeToSign;
}

int Form::getGradeToExecute() const {
	return gradeToExecute;
}

void Form::beSigned(Bureaucrat const& b) {
	if (b.getGrade() > gradeToSign)
		throw Form::GradeTooLowException();
	isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form: grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form: grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << "Form" << f.getName()
	   << " | signed: " << (f.get_Sign() ? "true" : "false")
	   << " | gradeToSign: " << f.getGradeToSign()
	   << " | gradeToExecute: " << f.getGradeToExecute();
	return os;
}