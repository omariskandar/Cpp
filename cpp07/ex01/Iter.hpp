/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 01:54:19 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/27 02:06:21 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template < typename T_array, typename T_function>
void iter(T_array *array, size_t length, T_function function)
{
    for (size_t i = 0; i < length; i++)
    {
        function(array[i]);
    }
}
#endif