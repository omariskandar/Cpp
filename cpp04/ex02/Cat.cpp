/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:58:01 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 19:05:12 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain())
{
    type = "Cat";
    std::cout << "[Cat] constructed\n";
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain())
{
    std::cout << "[Cat] copy-constructed\n";
    *brain = *other.brain;
}

Cat& Cat::operator=(const Cat& rhs)
{
    std::cout << "[Cat] copy-assigned\n";
    if (this != &rhs) {
        Animal::operator=(rhs);
        *brain = *rhs.brain;
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "[Cat] destroyed\n";
}

void Cat::makeSound() const
{
    std::cout << "[Cat] Meow!\n";
}

void Cat::setIdea(int idx, const std::string& idea)
{
    brain->setIdea(idx, idea);
}

const std::string& Cat::getIdea(int idx) const
{
    return brain->getIdea(idx);
}
