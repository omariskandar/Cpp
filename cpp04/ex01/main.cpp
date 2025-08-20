/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mian.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:49:23 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 18:53:05 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    std::cout << "== Polymorphic array (new/delete via Animal*) ==\n";
    const int N = 6;
    Animal* zoo[N];

    for (int i = 0; i < N; ++i) {
        if (i < N/2) zoo[i] = new Dog();
        else         zoo[i] = new Cat();
    }

    // sounds
    for (int i = 0; i < N; ++i) {
        std::cout << zoo[i]->getType() << ": ";
        zoo[i]->makeSound();
    }

    // delete via Animal*
    for (int i = 0; i < N; ++i) {
        delete zoo[i];
    }

    std::cout << "\n== Deep copy test (Dog) ==\n";
    Dog d1;
    d1.setIdea(0, "Chase the ball");
    d1.setIdea(1, "Guard the house");

    Dog d2 = d1; // copy-ctor (deep)
    std::cout << "d1[0]=" << d1.getIdea(0) << " | d2[0]=" << d2.getIdea(0) << "\n";
    d1.setIdea(0, "Eat treats");
    std::cout << "After modifying d1[0]\n";
    std::cout << "d1[0]=" << d1.getIdea(0) << " | d2[0]=" << d2.getIdea(0) << "\n";

    Dog d3;
    d3 = d1; // copy-assign (deep)
    std::cout << "d1[1]=" << d1.getIdea(1) << " | d3[1]=" << d3.getIdea(1) << "\n";
    d1.setIdea(1, "Nap time");
    std::cout << "After modifying d1[1]\n";
    std::cout << "d1[1]=" << d1.getIdea(1) << " | d3[1]=" << d3.getIdea(1) << "\n";

    std::cout << "\n== Deep copy test (Cat) ==\n";
    Cat c1;
    c1.setIdea(0, "Knock things off table");
    Cat c2(c1);
    std::cout << "c1[0]=" << c1.getIdea(0) << " | c2[0]=" << c2.getIdea(0) << "\n";
    c1.setIdea(0, "Sleep on keyboard");
    std::cout << "After modifying c1[0]\n";
    std::cout << "c1[0]=" << c1.getIdea(0) << " | c2[0]=" << c2.getIdea(0) << "\n";

    return 0;
}
