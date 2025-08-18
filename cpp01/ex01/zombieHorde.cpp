/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 01:07:11 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/19 01:08:49 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, const std::string& name) {
    if (N <= 0)
        return 0;

    Zombie* horde = new (std::nothrow) Zombie[N];
    if (!horde)
        return 0;

    for (int i = 0; i < N; ++i) {
        horde[i].setName(name);
    }
    return horde;
}