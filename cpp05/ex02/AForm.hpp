/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 00:03:45 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/24 00:03:48 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
    // Canonical
    AForm();
    AForm(const std::string& name, int signGrade, int execGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& rhs);
    virtual ~AForm();

    // Getters
    const std::string& getName() const;
    bool               getIsSigned() const;
    int                getSignGrade() const;
    int                getExecGrade() const;

    // Signing
    void beSigned(const Bureaucrat& b);

    // Execution
    void execute(const Bureaucrat& executor) const;
    virtual void executeAction() const = 0; // pure virtual

    // Exceptions
    class GradeTooHighException : public std::exception {
    public: const char* what() const throw(); };
    class GradeTooLowException : public std::exception {
    public: const char* what() const throw(); };
    class FormNotSignedException : public std::exception {
    public: const char* what() const throw(); };

private:
    const std::string _name;
    bool              _isSigned;
    const int         _signGrade;
    const int         _execGrade;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
