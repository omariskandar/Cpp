/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 23:25:57 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/24 23:27:15 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

#include <typeinfo>
#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif
