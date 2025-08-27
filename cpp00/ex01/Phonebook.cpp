/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:00:50 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/13 16:58:44 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/Phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

int PhoneBook::counter = 0;

static std::string fit10(const std::string& s)
{
    if (s.size() <= 10)
	{
        std::string pad(10 - s.size(), ' ');
        return pad + s;
    }
    return s.substr(0, 9) + ".";
}

PhoneBook::PhoneBook() : index(0)
{
}

void PhoneBook::display()
{
    std::size_t used = (PhoneBook::counter < 8) ? PhoneBook::counter : 8;

    std::cout << std::setw(10) << "INDEX" << "|"
              << std::setw(10) << "FIRST NAME" << "|"
              << std::setw(10) << "LAST NAME"  << "|"
              << std::setw(10) << "NICKNAME"   << "\n";

    for (std::size_t i = 0; i < used; ++i) {
        if (_contacts[i].getFirstName().empty()
            && _contacts[i].getLastName().empty()
            && _contacts[i].getNickName().empty()) {
            continue;
        }
        std::cout << std::setw(10) << (i + 1) << "|"
                  << fit10(_contacts[i].getFirstName()) << "|"
                  << fit10(_contacts[i].getLastName())  << "|"
                  << fit10(_contacts[i].getNickName())  << "\n";
    }
}

void PhoneBook::add()
{
    std::string first, last, nick, phone, secret;
    std::string line;
    std::cout << "First name: ";
    if (!std::getline(std::cin, first) || first.empty()) { std::cout << "Field cannot be empty.\n"; return; }
    std::cout << "Last name: ";
    if (!std::getline(std::cin, last) || last.empty()) { std::cout << "Field cannot be empty.\n"; return; }
    std::cout << "Nickname: ";
    if (!std::getline(std::cin, nick) || nick.empty()) { std::cout << "Field cannot be empty.\n"; return; }
    std::cout << "Phone number: ";
    if (!std::getline(std::cin, phone) || phone.empty()) { std::cout << "Field cannot be empty.\n"; return; }
    std::cout << "Darkest secret: ";
    if (!std::getline(std::cin, secret) || secret.empty()) { std::cout << "Field cannot be empty.\n"; return; }
    Contact c;
    c.setFirstName(first);
    c.setLastName(last);
    c.setNickName(nick);
    c.setPhone(phone);
    c.setSecret(secret);
    std::size_t slot = static_cast<std::size_t>(PhoneBook::counter % 8);
    _contacts[slot] = c;
    PhoneBook::counter++;
    std::cout << "Contact saved.\n";
}

void PhoneBook::search()
{
    std::size_t used = (PhoneBook::counter < 8) ? PhoneBook::counter : 8;
    if (used == 0)
	{
        std::cout << "PhoneBook is empty.\n";
        return;
    }
    display();
    std::cout << "Enter index to display (1-" << used << "): ";
    std::string line;
    if (!std::getline(std::cin, line))
		return;
    std::istringstream iss(line);
    int idx = 0;
    if (!(iss >> idx) || idx < 1 || static_cast<std::size_t>(idx) > used)
	{
        std::cout << "Invalid index.\n";
        return ;
    }
    std::size_t i = static_cast<std::size_t>(idx - 1);
    std::cout << "First name:     " << _contacts[i].getFirstName()  << "\n";
    std::cout << "Last name:      " << _contacts[i].getLastName()   << "\n";
    std::cout << "Nickname:       " << _contacts[i].getNickName()   << "\n";
    std::cout << "Phone number:   " << _contacts[i].getPhone()      << "\n";
    std::cout << "Darkest secret: " << _contacts[i].getSecret()     << "\n";
}
