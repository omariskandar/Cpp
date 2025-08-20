/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:30:07 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 16:30:18 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    ScavTrap();                                // default -> name "noname"
    explicit ScavTrap(const std::string& n);   // with name
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& rhs);
    virtual ~ScavTrap();

    void attack(const std::string& target);    // override (optional but nice)
    void guardGate();                          // special ability
};

#endif 
