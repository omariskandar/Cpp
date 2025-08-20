/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:53:57 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 18:01:52 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "[Animal] constructer called\n";
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "[Animal] copy-constructed\n";
}

Animal Animal::operator=(const Animal& rhs)
{
	if (this != &rhs)
		type = rhs.type;
	std::cout << "[Animal] copy-assigned\n";
    return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destroyed\n";
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
    std::cout << "[Animal] *generic animal noise*\n";
}
