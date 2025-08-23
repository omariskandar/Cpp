/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 00:03:55 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/24 00:03:57 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _signGrade(1), _execGrade(1) {}

AForm::AForm(const std::string& name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned),
      _signGrade(other._signGrade), _execGrade(other._execGrade) {}

AForm& AForm::operator=(const AForm& rhs) {
    if (this != &rhs)
        _isSigned = rhs._isSigned;
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getSignGrade() const { return _signGrade; }
int AForm::getExecGrade() const { return _execGrade; }

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const {
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _execGrade)
        throw GradeTooLowException();
    executeAction(); // delegate to derived class
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}
const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}
const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

// Output operator
std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form " << f.getName()
       << " | signed: " << (f.getIsSigned() ? "yes" : "no")
       << " | sign grade: " << f.getSignGrade()
       << " | exec grade: " << f.getExecGrade();
    return os;
}
