/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 00:04:59 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/24 00:07:32 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
    std::ofstream ofs((_target + "_shrubbery").c_str());
    ofs << "   ccee88oo\n"
           " C8O8O8Q8PoOb o8oo\n"
           "dOB69QO8PdUOpugoO9bD\n"
           "CgggbU8OU qOp qOdoUOdcb\n"
           "   6OuU  /p u gcoUodpP\n"
           "      \\\\//  /douUP\n"
           "        \\\\////\n"
           "         |||/\\\n"
           "         |||\\/\n"
           "         |||||\n"
           "   .....//||||\\....\n";
}
