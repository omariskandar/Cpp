/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 20:51:33 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/24 00:12:27 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat();

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		const std::string& getName() const;
		int  getGrade() const;
		void incrementGrade();
		void decrementGrade();

		void executeForm(const AForm& f) const;
		void signForm(AForm& f);
	private:
	    static const int kMaxGrade = 1;
	    static const int kMinGrade = 150;

		const std::string _name;
		int	_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
