/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:11:07 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/28 15:40:23 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int target)
{
	typename T::iterator it = std::find(container.begin(), container.end(), target);
	if (it == container.end())
        throw std::runtime_error("Target not found");
	return (it);
}

#endif
