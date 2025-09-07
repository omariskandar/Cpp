/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:35:13 by oiskanda          #+#    #+#             */
/*   Updated: 2025/09/07 19:06:10 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

size_t comparisons = 0;

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
        numbers.push_back(std::atoi(argv[i]));
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
	return ;
}

int binarySearch(std::vector<int> vec, int target, int high)
{
	if (vec.empty())
		return 0;
	int low = 0;
	if (high >= vec.size())
		high = vec.size() - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		comparisons++;
		if (vec[mid] == target)
			return mid;
		else if (vec[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return low;
}

int jacobsthalSeq(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int prev2 = 0, prev1 = 1, curr = 0;
    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

std::vector<int> JacobthalIndices(int size)
{
    std::vector<int> jacobSequence;
    int jacobIndex = 3;
    while (jacobsthalSeq(jacobIndex) <= size)
    {
        jacobSequence.push_back(jacobsthalSeq(jacobIndex));
        jacobIndex++;
    }
    return jacobSequence;
}

std::vector<size_t> buildJacobFullOrder(size_t pend_len)
{
    std::vector<size_t> order;
    if (pend_len == 0)
		return order;
    std::vector<char> used(pend_len, 0);
    order.push_back(0);
    used[0] = 1;
    std::vector<size_t> J;
    J.push_back(0);
    J.push_back(1);
    while (true)
	{
        size_t n = J.size();
        size_t next = J[n-1] + 2 * J[n-2];
        if (next > pend_len)
			break;
        J.push_back(next);
    }
    size_t prevJ = 1;
    for (size_t k = 2; k < J.size(); ++k)
	{
        size_t hi = J[k];
        size_t lo = prevJ + 1;
        if (lo < 2) lo = 2;

        if (lo <= hi)
		{
            for (size_t x = hi; ; --x)
			{
                size_t idx0 = x - 1;
                if (idx0 < pend_len && !used[idx0])
				{
                    order.push_back(idx0);
                    used[idx0] = 1;
                }
                if (x == lo)
					break;
            }
        }
        prevJ = hi;
    }
    if (pend_len >= 2)
	{
        size_t x = pend_len - 1;
        while (true)
		{
            if (!used[x])
			{
                order.push_back(x);
                used[x] = 1;
            }
            if (x == 1) break;
            --x;
        }
    }
    return order;
}


