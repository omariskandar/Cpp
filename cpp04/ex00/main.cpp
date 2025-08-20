/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:20:31 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 18:22:33 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    std::cout << "== Correct polymorphism ==\n";
    const Animal* meta = new Animal();
    const Animal* j    = new Dog();
    const Animal* i    = new Cat();

    std::cout << j->getType() << std::endl; // Dog
    std::cout << i->getType() << std::endl; // Cat

    i->makeSound(); // Cat sound
    j->makeSound(); // Dog sound
    meta->makeSound(); // Animal sound

    delete meta;
    delete j;
    delete i;

    std::cout << "\n== Wrong polymorphism (no virtual) ==\n";
    const WrongAnimal* wmeta = new WrongAnimal();
    const WrongAnimal* wi    = new WrongCat();

    std::cout << wi->getType() << std::endl;
    wi->makeSound();
    wmeta->makeSound();

    delete wmeta;
    delete wi;

    std::cout << "\n== Extra: array of Animal* ==\n";
    Animal* zoo[4];
    for (int k = 0; k < 4; ++k)
        zoo[k] = (k % 2 == 0) ? static_cast<Animal*>(new Dog()) : static_cast<Animal*>(new Cat());

    for (int k = 0; k < 4; ++k) {
        std::cout << zoo[k]->getType() << ": ";
        zoo[k]->makeSound();
    }
    for (int k = 0; k < 4; ++k)
        delete zoo[k];

    return 0;
}
