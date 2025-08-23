/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 22:44:30 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/23 23:44:12 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("OMAR"), _isSigned(false), _signGrade(1), _execGrade(1)
{
	std::cout << "Default constructer called\n";
}

Form::Form(const std::string& name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
	{
		throw GradeTooHighException();
	}

    if (signGrade > 150 || execGrade > 150)
	{
        throw GradeTooLowException();
	}

	std::cout << "Constructor called for " << _name << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
		std::cout << "copy constructer called\n";
}

Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
		_isSigned = rhs._isSigned;
	return *this;
}

Form::~Form()
{
	std::cout << "Destructor called for " << _name << std::endl;
}

const std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int	Form::getExecGrade() const
{
	return _execGrade;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form " << f.getName()
       << " | signed: " << (f.getIsSigned() ? "yes" : "no")
       << " | sign grade: " << f.getSignGrade()
       << " | exec grade: " << f.getExecGrade();
    return os;
}
