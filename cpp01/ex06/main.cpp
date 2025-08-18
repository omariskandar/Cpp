/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 01:45:23 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/19 01:45:25 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ex06/main.cpp
#include "Harl.hpp"
#include <iostream>
#include <string>

static int level_index(const std::string& level) {
    if (level == "DEBUG")   return 0;
    if (level == "INFO")    return 1;
    if (level == "WARNING") return 2;
    if (level == "ERROR")   return 3;
    return -1;
}

static void print_header(const char* hdr) {
    std::cout << "[ " << hdr << " ]" << std::endl;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << (argc > 0 ? argv[0] : "./harlFilter")
                  << " <DEBUG|INFO|WARNING|ERROR>" << std::endl;
        return 1;
    }

    const std::string level = argv[1];
    Harl harl;

    switch (level_index(level)) {
        case 0: // DEBUG -> print all
            print_header("DEBUG");
            harl.complain("DEBUG");
            std::cout << std::endl;
            // fall through
        case 1: // INFO
            print_header("INFO");
            harl.complain("INFO");
            std::cout << std::endl;
            // fall through
        case 2: // WARNING
            print_header("WARNING");
            harl.complain("WARNING");
            std::cout << std::endl;
            // fall through
        case 3: // ERROR
            print_header("ERROR");
            harl.complain("ERROR");
            break;

        default:
            std::cout << "[ Probably complaining about insignificant problems ]"
                      << std::endl;
            break;
    }

    return 0;
}
