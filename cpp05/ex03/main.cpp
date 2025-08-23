/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 00:07:56 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/24 00:18:53 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    Intern intern;
    Bureaucrat boss("Boss", 1);

    std::cout << "---- Intern makes forms ----" << std::endl;

    AForm* f1 = intern.makeForm("shrubbery creation", "garden");
    AForm* f2 = intern.makeForm("robotomy request", "Marvin");
    AForm* f3 = intern.makeForm("presidential pardon", "Ford Prefect");
    AForm* f4 = intern.makeForm("nonsense form", "Nobody"); // should fail

    std::cout << "---- Bureaucrat signs and executes ----" << std::endl;

    if (f1) { boss.signForm(*f1); boss.executeForm(*f1); delete f1; }
    if (f2) { boss.signForm(*f2); boss.executeForm(*f2); delete f2; }
    if (f3) { boss.signForm(*f3); boss.executeForm(*f3); delete f3; }
    if (f4) { boss.signForm(*f4); boss.executeForm(*f4); delete f4; }

    return 0;
}
