/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 01:24:50 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/27 01:49:37 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

template <typename T>
T max(T& x, T& y)
{
    if (x > y)
        return x;
    else
        return y;
}

template <typename T>
T min(T& x, T& y)
{
    if (x < y)
        return x;
    else
        return y;
}

template <typename T>
void swap(T& x, T& y)
{
    T temp;

    temp = x;
    x = y;
    y = temp;
}
#endif