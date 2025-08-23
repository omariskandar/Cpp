/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:40:31 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/23 21:40:33 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        // Valid bureaucrat
        Bureaucrat b1("Alice", 42);
        std::cout << b1 << std::endl;

        // Test increment
        b1.incrementGrade();
        std::cout << "After increment: " << b1 << std::endl;

        // Test decrement
        b1.decrementGrade();
        std::cout << "After decrement: " << b1 << std::endl;

        // Boundary test: grade too high
        Bureaucrat top("Top", 1);
        std::cout << top << std::endl;
        std::cout << "Trying to increment Top beyond limit..." << std::endl;
        top.incrementGrade(); // should throw

    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "----" << std::endl;

    try {
        // Boundary test: grade too low
        Bureaucrat low("Low", 150);
        std::cout << low << std::endl;
        std::cout << "Trying to decrement Low beyond limit..." << std::endl;
        low.decrementGrade(); // should throw

    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "----" << std::endl;

    try {
        // Invalid construction (too high)
        Bureaucrat invalid("Invalid", 0);
        std::cout << invalid << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception caught at construction: " << e.what() << std::endl;
    }

    try {
        // Invalid construction (too low)
        Bureaucrat invalid2("Invalid2", 200);
        std::cout << invalid2 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception caught at construction: " << e.what() << std::endl;
    }

    return 0;
}
