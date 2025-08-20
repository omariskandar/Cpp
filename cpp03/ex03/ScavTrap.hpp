/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:30:07 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 16:47:47 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
    ScavTrap();
    explicit ScavTrap(const std::string& n);
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& rhs);
    virtual ~ScavTrap();

    virtual void attack(const std::string& target);
    void guardGate();
};
#endif
