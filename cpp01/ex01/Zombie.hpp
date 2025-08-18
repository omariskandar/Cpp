/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 01:05:39 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/19 01:05:58 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    public:
        Zombie();
        ~Zombie();

        void announce() const;
        void setName(const std::string& name);

    private:
        std::string _name;
};

Zombie* zombieHorde(int N, const std::string& name);

#endif 