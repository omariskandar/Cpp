/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:45:32 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 18:46:38 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "[Brain] constructed\n";
}

Brain::Brain(const Brain& other)
{
    std::cout << "[Brain] copy-constructed\n";
    for (int i = 0; i < 100; ++i)
		ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& rhs)
{
    std::cout << "[Brain] copy-assigned\n";
    if (this != &rhs)
	{
        for (int i = 0; i < 100; ++i)
			ideas[i] = rhs.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "[Brain] destroyed\n";
}

const std::string& Brain::getIdea(int idx) const
{
    static const std::string empty;
    if (idx < 0 || idx >= 100)
		return empty;
    return ideas[idx];
}

void Brain::setIdea(int idx, const std::string& idea)
{
    if (idx < 0 || idx >= 100)
		return;
    ideas[idx] = idea;
}
