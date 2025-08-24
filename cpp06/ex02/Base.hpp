/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 23:25:32 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/24 23:25:33 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base {
public:
    virtual ~Base(); // must be virtual for dynamic_cast to work properly
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif
