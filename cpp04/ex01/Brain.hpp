/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:43:27 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 18:43:35 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& rhs);
    ~Brain();

    const std::string& getIdea(int idx) const;
    void setIdea(int idx, const std::string& idea);

private:
    std::string ideas[100];
};

#endif
