/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:08:56 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 18:12:48 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "[Dog] constructed\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "[Cat] copy-constructed\n";
}

Cat& Cat::operator=(const Cat& rhs)
{
    if (this != &rhs)
        Animal::operator=(rhs);
    std::cout << "[Cat] copy-assigned\n";
    return *this;
}

Cat::~Cat()
{
    std::cout << "[Cat] destroyed\n";
}

void Cat::makeSound() const
{
    std::cout << "[Cat] Meow!\n";
}
