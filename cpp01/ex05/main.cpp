/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 01:39:34 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/19 01:39:52 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ex05/main.cpp
#include "Harl.hpp"
#include <iostream>

int main() {
    Harl harl;

    std::cout << "[DEBUG]\n";
    harl.complain("DEBUG");

    std::cout << "\n[INFO]\n";
    harl.complain("INFO");

    std::cout << "\n[WARNING]\n";
    harl.complain("WARNING");

    std::cout << "\n[ERROR]\n";
    harl.complain("ERROR");

    std::cout << "\n[UNKNOWN]\n";
    harl.complain("NOT_A_LEVEL");

    return 0;
}
