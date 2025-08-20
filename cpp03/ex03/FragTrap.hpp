/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:11:52 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 16:47:59 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
    FragTrap();
    explicit FragTrap(const std::string& n);
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& rhs);
    virtual ~FragTrap();

    void highFivesGuys(void) const;
};
#endif
