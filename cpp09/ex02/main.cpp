/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:41:46 by oiskanda          #+#    #+#             */
/*   Updated: 2025/09/01 17:31:03 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	std::vector<int> nums = convertToVector(argc, argv);
	checkSorted(nums);
    std::pair<std::vector<int>, std::vector<int> > result = slpitToPairs(nums);
    std::vector<int> winners = result.first;
    std::vector<int> losers  = result.second;
    // std::pair<std::vector<int>, std::vector<int> > result = slpitToPairs(winners);
    std::cout << "Winners: ";
    for (std::vector<int>::size_type k = 0; k < winners.size(); ++k)
        std::cout << winners[k] << " ";
    std::cout << "\nLosers: ";
    for (std::vector<int>::size_type k = 0; k < losers.size(); ++k)
        std::cout << losers[k] << " ";
    std::cout << std::endl;

    return 0;
}
