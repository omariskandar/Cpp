/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 00:07:56 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/24 00:07:58 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << shrub << std::endl;
        std::cout << robo << std::endl;
        std::cout << pardon << std::endl;

        // signing
        boss.signForm(shrub);
        boss.signForm(robo);
        boss.signForm(pardon);

        // executing
        boss.executeForm(shrub);
        boss.executeForm(robo);
        boss.executeForm(pardon);

        // intern will fail
        intern.signForm(robo);
        intern.executeForm(robo);
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
