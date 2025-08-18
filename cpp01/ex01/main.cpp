/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 01:07:28 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/19 01:07:48 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>  // atoi
#include <string>

int main(int argc, char** argv) {
    int N = 5;
    std::string name = "Hordeling";

    if (argc >= 2) N = std::atoi(argv[1]);
    if (argc >= 3) name = argv[2];

    Zombie* z = zombieHorde(N, name);
    if (!z) {
        std::cout << "Failed to create horde (N=" << N << ").\n";
        return 1;
    }

    for (int i = 0; i < N; ++i)
        z[i].announce();

    delete[] z;
    return 0;
}