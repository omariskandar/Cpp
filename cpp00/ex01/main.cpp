/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:05:19 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/15 13:13:31 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "includes/Phonebook.hpp"

int main() {
    PhoneBook pb;
    std::string cmd;

    for (;;)
	{
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, cmd))
			break;
        if (cmd == "ADD")
			pb.add();
        else if (cmd == "SEARCH")
			pb.search();
        else if (cmd == "EXIT")
			break;
    }
    return 0;
}
