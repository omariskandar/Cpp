/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:35:13 by oiskanda          #+#    #+#             */
/*   Updated: 2025/09/01 17:31:34 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	checkNegative(std::vector <int> numbers)
{
	for (std::vector<int>::size_type i = 0; i < numbers.size(); i++)
		if (numbers[i] < 0)
		{
			std::cout << "Negative numbers\n";
			return (0);
		}
	return (1);
}

int	checkDuplicates(std::vector <int> numbers)
{
	for (std::vector<int>::size_type i = 0; i < numbers.size(); i++)
	{
		for (std::vector<int>::size_type j = i + 1; j < numbers.size(); j++)
		{
			if (numbers[j] == numbers[i])
			{
				std::cout << "Duplicates found\n";
				return (1);
			}
		}
	}
	return (0);
}

std::vector<int> convertToVector(int argc, char **argv)
{
	std::vector <int> numbers;
	for (int i = 1; i < argc; i++)
	{
		numbers.push_back(atoi(argv[i]));
	}
	return numbers;
}

void checkSorted(std::vector <int> numbers)
{
	for(std::vector<int>::size_type i = 0; i < numbers.size(); i++)
	{
		for(std::vector<int>::size_type j = i + 1; j < numbers.size(); j++)
		{
			if (numbers[i] > numbers[j])
				return ;
		}
	}
	std::cout << "Sorted\n";
	exit(0);
}

std::pair<std::vector<int>, std::vector<int> >
slpitToPairs(std::vector <int>& numbers)
{
	std::vector <int> losers;
	std::vector <int> winners;
	for (std::vector<int>::size_type i = 0; i < numbers.size(); i += 2)
	{
        if (numbers[i] > numbers[i + 1])
        {
            winners.push_back(numbers[i]);
            losers.push_back(numbers[i + 1]);
        }
        else
        {
            winners.push_back(numbers[i + 1]);
            losers.push_back(numbers[i]);
        }
	}
    return std::make_pair(winners, losers);
}
