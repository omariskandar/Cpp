/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:19:48 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 18:21:43 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "[WrongCat] constructed\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "[WrongCat] copy-constructed\n";
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
    if (this != &rhs)
        WrongAnimal::operator=(rhs);
    std::cout << "[WrongCat] copy-assigned\n";
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "[WrongCat] destroyed\n";
}

void WrongCat::makeSound() const
{
    std::cout << "[WrongCat] Meooow?\n";
}
