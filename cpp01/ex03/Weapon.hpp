/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 01:24:29 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/19 01:24:39 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ex03/Weapon.hpp
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
public:
    Weapon();
    explicit Weapon(const std::string& type);

    const std::string& getType() const;
    void               setType(const std::string& type);

private:
    std::string _type;
};

#endif
