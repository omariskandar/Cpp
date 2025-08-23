/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 23:40:54 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/23 23:51:01 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	    try {
        std::cout << "== Using Bureaucrat::signForm ==" << std::endl;
        Bureaucrat alice("Alice", 40);
        Form contract("Contract", 50, 30);

        std::cout << alice << std::endl;
        std::cout << contract << std::endl;

        alice.signForm(contract); // success
        std::cout << contract << std::endl;

        Bureaucrat bob("Bob", 100);
        Form secret("Top Secret Form", 50, 20);

        std::cout << bob << std::endl;
        std::cout << secret << std::endl;

        bob.signForm(secret); // fails, exception caught
        std::cout << secret << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
	
    try {
        std::cout << "== Valid signing ==" << std::endl;
        Bureaucrat b1("Alice", 40);
        Form f1("Contract", 50, 30);

        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;

        f1.beSigned(b1);
        std::cout << "After signing: " << f1 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "----" << std::endl;

    try {
        std::cout << "== Signing with too low grade ==" << std::endl;
        Bureaucrat b2("Bob", 100);
        Form f2("Top Secret Form", 50, 20);

        std::cout << b2 << std::endl;
        std::cout << f2 << std::endl;

        f2.beSigned(b2);
        std::cout << "After signing: " << f2 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "----" << std::endl;

    try {
        std::cout << "== Invalid form construction (too high sign grade) ==" << std::endl;
        Form badForm("Impossible", 0, 50);
        std::cout << badForm << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception at construction: " << e.what() << std::endl;
    }

    std::cout << "----" << std::endl;

    try {
        std::cout << "== Invalid form construction (too low exec grade) ==" << std::endl;
        Form badForm2("Another Impossible", 100, 200);
        std::cout << badForm2 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception at construction: " << e.what() << std::endl;
    }

    return 0;
}
