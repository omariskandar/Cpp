/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 20:51:33 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/23 23:53:25 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

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

		void signForm(Form& f);
	private:
	    static const int kMaxGrade = 1;
	    static const int kMinGrade = 150;

		const std::string _name;
		int	_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
