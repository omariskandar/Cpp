/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:11:52 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 16:20:38 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		explicit FragTrap(const std::string& n);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& rhs);
		~FragTrap();

		void highFivesGuys(void);

};
#endif
