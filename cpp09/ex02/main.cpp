/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:41:46 by oiskanda          #+#    #+#             */
/*   Updated: 2025/09/03 02:47:21 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	std::vector<int> nums = convertToVector(argc, argv);
    if (checkNegative(nums) && checkDuplicates(nums))
        return 1;
    std::vector<int> winners = makingPairs(nums);
    // std::vector<int> losers = makingPairs(nums);
    for (std::vector<int>::size_type i = 0; winners[i]; i++)
        std::cout << winners[i] << " ";
    std::cout << std::endl;
    return 0;
}
