/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mian.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:58:12 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 19:05:23 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    std::cout << "== Polymorphic array (Animal* pointing to Dog/Cat) ==\n";
    const int N = 4;
    Animal* zoo[N];

    for (int i = 0; i < N; ++i)
        zoo[i] = (i % 2 == 0) ? static_cast<Animal*>(new Dog()) : static_cast<Animal*>(new Cat());

    for (int i = 0; i < N; ++i) {
        std::cout << zoo[i]->getType() << ": ";
        zoo[i]->makeSound();
    }

    for (int i = 0; i < N; ++i)
        delete zoo[i];

    std::cout << "\n== Deep copy check ==\n";
    Dog d1;
    d1.setIdea(0, "Chase cats");
    Dog d2 = d1; // copy-ctor
    std::cout << "d1[0]=" << d1.getIdea(0) << " | d2[0]=" << d2.getIdea(0) << "\n";
    d1.setIdea(0, "Eat treats");
    std::cout << "after change d1[0]=" << d1.getIdea(0) << " | d2[0]=" << d2.getIdea(0) << "\n";

    Cat c1;
    c1.setIdea(0, "Nap in the sun");
    Cat c2; c2 = c1; // copy-assign
    std::cout << "c1[0]=" << c1.getIdea(0) << " | c2[0]=" << c2.getIdea(0) << "\n";
    c1.setIdea(0, "Walk on keyboard");
    std::cout << "after change c1[0]=" << c1.getIdea(0) << " | c2[0]=" << c2.getIdea(0) << "\n";

    return 0;
}
