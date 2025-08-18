/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 01:45:03 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/19 01:45:12 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ex06/Harl.cpp
#include "Harl.hpp"
#include <iostream>

typedef void (Harl::*HarlFn)();

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug(void) {
    std::cout
        << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-"
           "special-ketchup burger. I really do!"
        << std::endl;
}

void Harl::info(void) {
    std::cout
        << "I cannot believe adding extra bacon costs more money. You didn’t put "
           "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
        << std::endl;
}

void Harl::warning(void) {
    std::cout
        << "I think I deserve to have some extra bacon for free. I’ve been coming for "
           "years, whereas you started working here just last month."
        << std::endl;
}

void Harl::error(void) {
    std::cout
        << "This is unacceptable! I want to speak to the manager now."
        << std::endl;
}

void Harl::complain(const std::string& level) {
    static const char* names[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    static HarlFn      funcs[4] = {
        &Harl::debug, &Harl::info, &Harl::warning, &Harl::error
    };

    for (int i = 0; i < 4; ++i) {
        if (level == names[i]) {
            (this->*funcs[i])();
            return;
        }
    }
    // No output on unknown level here; main handles the fallback message.
}
