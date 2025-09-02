/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:35:13 by oiskanda          #+#    #+#             */
/*   Updated: 2025/09/03 02:48:34 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int comparisons = 0;

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

static int checkValidNumber(char *argv)
{
    for (int i = 0; argv[i]; i++)
    {
        if (!isdigit(argv[i]))
        {
            std::cout << "Must only contain digits\n";
            return (1);
        }
    }
    return (0);
}

std::vector<int> convertToVector(int argc, char **argv)
{
	std::vector <int> numbers;

	for (int i = 1; i < argc; i++)
	{
        if (checkValidNumber(argv[i]))
            exit (1);
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

std::vector<int> makingPairs(std::vector<int> nums)
{
    std::vector<int> winners;
    std::vector<int> losers;
    
    for (std::vector<int>::size_type i = 0; i < nums.size(); i += 2)
    {
        if (nums[i] < nums[i + 1])
        {
            winners.push_back(nums[i + 1]);
            losers.push_back(nums[i]);
        }
        else
        {
            winners.push_back(nums[i]);
            losers.push_back(nums[i + 1]);
        }
    }
    if (nums.size() % 2 != 0)
        winners.push_back(nums[nums.size()]);
    return (losers);
}