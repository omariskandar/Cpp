/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 01:38:33 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/19 01:38:44 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
public:
    Harl();
    ~Harl();

    void complain(const std::string& level);

private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};

#endif
