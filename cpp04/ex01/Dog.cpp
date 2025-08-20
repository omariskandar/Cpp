/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:47:46 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 18:48:39 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain())
{
    type = "Dog";
    std::cout << "[Dog] constructed\n";
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain())
{
    std::cout << "[Dog] copy-constructed\n";
    *brain = *other.brain;
}

Dog& Dog::operator=(const Dog& rhs)
{
    std::cout << "[Dog] copy-assigned\n";
    if (this != &rhs)
	{
        Animal::operator=(rhs);
        *brain = *rhs.brain;
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "[Dog] destroyed\n";
}

void Dog::makeSound() const
{
    std::cout << "[Dog] Woof!\n";
}

void Dog::setIdea(int idx, const std::string& idea)
{
    brain->setIdea(idx, idea);
}

const std::string& Dog::getIdea(int idx) const
{
    return brain->getIdea(idx);
}
