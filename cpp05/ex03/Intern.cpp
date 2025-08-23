/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 00:20:31 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/24 00:20:32 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern& other) {
    (void)other;
    std::cout << "Intern copied" << std::endl;
}

Intern& Intern::operator=(const Intern& rhs) {
    (void)rhs;
    std::cout << "Intern assigned" << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destroyed" << std::endl;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    if (formName == names[0]) {
        std::cout << "Intern creates " << formName << std::endl;
        return new ShrubberyCreationForm(target);
    }
    else if (formName == names[1]) {
        std::cout << "Intern creates " << formName << std::endl;
        return new RobotomyRequestForm(target);
    }
    else if (formName == names[2]) {
        std::cout << "Intern creates " << formName << std::endl;
        return new PresidentialPardonForm(target);
    }
    else {
        std::cout << "Intern cannot create form: " << formName << std::endl;
        return NULL;
    }
}
