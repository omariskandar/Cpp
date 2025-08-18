/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 01:25:04 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/19 01:25:21 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ex03/HumanA.hpp
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
public:
    HumanA(const std::string& name, Weapon& weapon);
    void attack() const;

private:
    std::string _name;
    Weapon&     _weapon;
};

#endif
