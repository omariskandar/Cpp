/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 22:44:27 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/23 23:45:15 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string& name, int signGrade, int execGrade);
		Form(const Form& other);
		Form& operator=(const Form& rhs);
		~Form();

		const std::string getName() const;
		bool getIsSigned() const;
		int	getSignGrade() const;
		int	getExecGrade() const;

		void beSigned(const Bureaucrat& b);

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

	private:
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _execGrade;

};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
