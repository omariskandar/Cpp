/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:19:20 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 18:20:53 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "[WrongAnimal] constructed\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
    std::cout << "[WrongAnimal] copy-constructed\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
    if (this != &rhs) type = rhs.type;
    std::cout << "[WrongAnimal] copy-assigned\n";
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "[WrongAnimal] destroyed\n";
}

std::string WrongAnimal::getType() const { return type; }

void WrongAnimal::makeSound() const
{
    std::cout << "[WrongAnimal] *wrong generic noise*\n";
}
