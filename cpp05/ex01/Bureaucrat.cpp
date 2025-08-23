// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/08/23 21:07:00 by oiskanda          #+#    #+#             */
// /*   Updated: 2025/08/23 21:46:12 by oiskanda         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("OMAR"), _grade(24)
{
	std::cout << "Default constructer called\n";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (grade < kMaxGrade)
		throw GradeTooHighException();
	else if (grade > kMinGrade)
		throw GradeTooLowException();
	std::cout << "Constructor called for " << _name << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout << "copy constructer called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
		_grade = rhs._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called for " << _name << std::endl;
}

const std::string& Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < kMaxGrade)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > kMinGrade)
        throw GradeTooLowException();
    _grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

void Bureaucrat::signForm(Form& f) {
    try {
        f.beSigned(*this);
        std::cout << _name << " signs " << f.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << _name << " cannot sign " << f.getName()
                  << " because " << e.what() << std::endl;
    }
}
