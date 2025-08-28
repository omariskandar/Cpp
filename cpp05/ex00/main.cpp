/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:40:31 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/27 13:35:52 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 42);
        std::cout << b1 << std::endl;

        b1.incrementGrade();
        std::cout << "After increment: " << b1 << std::endl;
        b1.decrementGrade();
        std::cout << "After decrement: " << b1 << std::endl;

        Bureaucrat top("Top", 1);
        std::cout << top << std::endl;
        std::cout << "Trying to increment Top beyond limit..." << std::endl;
        top.incrementGrade();

    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "----" << std::endl;

    try {
        Bureaucrat low("Low", 150);
        std::cout << low << std::endl;
        std::cout << "Trying to decrement Low beyond limit..." << std::endl;
        low.decrementGrade();

    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "----" << std::endl;

    try {
        Bureaucrat invalid("Invalid", 0);
        std::cout << invalid << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception caught at construction: " << e.what() << std::endl;
    }

    try {
        Bureaucrat invalid2("Invalid2", 200);
        std::cout << invalid2 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception caught at construction: " << e.what() << std::endl;
    }

    return 0;
}
