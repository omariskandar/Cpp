/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:12:30 by oiskanda          #+#    #+#             */
/*   Updated: 2025/09/10 19:02:47 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int comparisons = 0;

PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)other;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
		(void)other;
	return (*this);
}

PmergeMe::~PmergeMe() {};

int BinarySearch(const std::vector <int> &vec, int target, int high)
{
	if (vec.empty())
		return 0;
	int low = 0;
	if (high >= static_cast<int>(vec.size()))
		high = vec.size() - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		++comparisons;
		if (vec[mid] == target)
			return mid;
		else if (vec[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return low;
}

int jacobsThalSeq(int n)
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
    while (jacobsThalSeq(jacobIndex) <= size)
    {
        jacobSequence.push_back(jacobsThalSeq(jacobIndex));
        jacobIndex++;
    }
    return jacobSequence;
}

int getIndex(std::vector<int>& vec, int value)
{
	if (value == -1)
		return vec.size();
    std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), value);
    	if (it != vec.end())
        	return static_cast<int>(std::distance(vec.begin(), it));
    return -1;
}

static void genInsertionOrder(std::vector<int>& jacob, std::vector<int>& pend)
{
    std::vector<int>::iterator it = jacob.begin();
    std::vector<int> pushedNumbers;
    std::vector<int> temp;
    while (it != jacob.end())
    {
        int x;
        if (*it >= 0)
        {
            x = *it;
            while (x > 1)
            {
                if (std::find(pushedNumbers.begin(), pushedNumbers.end(), x) == pushedNumbers.end())
                {
                    temp.push_back(x - 1);
                    pushedNumbers.push_back(x);
                }
                else
                    break;
                x--;
            }
        }
        it++;
    }
    if (temp.size() == pend.size())
        jacob = temp;
    else
    {
        int x = pend.size();
        while (temp.size() < pend.size())
        {
            if (std::find(pushedNumbers.begin(), pushedNumbers.end(), x) == pushedNumbers.end())
            {
                temp.push_back(x - 1);
                pushedNumbers.push_back(x);
            }
            else
                break;
            x--;
        }
        jacob = temp;
    }
}


int findSecondByFirst(const std::vector< std::pair<int,int> >& vp, int first)
{
    for (std::vector< std::pair<int,int> >::const_iterator it = vp.begin();
         it != vp.end(); ++it)
    {
        if (it->first == first)
            return it->second;
    }
    return -1;
}

int findFirstBySecond(const std::vector< std::pair<int,int> >& vp, int second)
{
    for (std::vector< std::pair<int,int> >::const_iterator it = vp.begin();
         it != vp.end(); ++it)
    {
        if (it->second == second)
            return it->first;
    }
    return -1;
}

static std::vector<int> arrangeLosers(std::vector<std::pair<int , int> > main_chain, std::vector<int> losers, std::vector<int> winners, int odd)
{
	std::vector<int> temp;
	PmergeMe a;

	for (std::vector<int>::iterator it = winners.begin(); it != winners.end(); ++it)
	{
		int val = *it;
		int x = findSecondByFirst(main_chain, val);
		temp.push_back(x);
	}

	if (odd != -1)
		temp.push_back(odd);
	losers.swap(temp);
	return losers;
}

void PmergeMe::mergeInsertionSort(std::vector<int>& a)
{
	if (a.size() <= 1)
		return ;

	std::vector<std::pair<int , int> > main_chain;
	std::vector<int> winners, losers;
	int odd = -1;
	for (size_t i = 0; i < a.size(); i += 2)
	{
		if (i + 1 < a.size())
		{
			comparisons++;
			if (a[i] > a[i + 1])
				std::swap(a[i], a[i + 1]);
			main_chain.push_back(std::make_pair(a[i + 1], a[i]));
		}
		else
			odd = a[i];
	}

	for (size_t i = 0; i < main_chain.size(); ++i)
	{
		winners.push_back(main_chain[i].first);
		losers.push_back(main_chain[i].second);
	}

	if(odd != -1)
		losers.push_back(odd);

	mergeInsertionSort(winners);

	losers = arrangeLosers(main_chain, losers, winners, odd);
	std::vector<int> insertion_order = JacobthalIndices(losers.size());
	genInsertionOrder(insertion_order, losers);

	std::vector<int>::iterator pos1;
	pos1 = winners.begin() + 0;

	if (insertion_order.size() > 1)
	{
		winners.insert(pos1, losers[0]);
		losers[0] = -1;
	}

	for (std::vector<int>::iterator it = insertion_order.begin(); it != insertion_order.end(); ++it)
	{
		int index = *it;
		if (index < 0 || static_cast<size_t>(index) >= losers.size())
			continue ;
		int val = losers[index];
		if (val == -1)
			continue ;
		int lim = getIndex(winners, findFirstBySecond(main_chain, val)) - 1;
		std::vector<int>::iterator pos;
		pos = winners.begin() + BinarySearch(winners, val, lim);
		winners.insert(pos, val);
	}

	a.swap(winners);
}

int getIndex(std::deque<int>& vec, int value)
{
    if (value == -1) return (int)vec.size();
    for (std::deque<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        if (*it == value) return (int)std::distance(vec.begin(), it);
    }
    return -1;
}

int BinarySearch(const std::deque<int>& vec, int target, int high)
{
    if (vec.empty()) return 0;
    int low = 0;
    if (high >= (int)vec.size()) high = (int)vec.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        ++comparisons;                 // count one key comparison step
        if (vec[mid] == target)        // equality
            return mid;
        else if (vec[mid] > target)    // greater
            high = mid - 1;
        else                           // less
            low = mid + 1;
    }
    return low; // insertion point
}

void PmergeMe::mergeInsertionSort(std::deque<int>& a)
{
    if (a.size() <= 1)
        return;

    std::vector< std::pair<int,int> > main_chain;
    std::deque<int> winners;
    std::vector<int> losers;
    int odd = -1;

    // pair
    for (size_t i = 0; i < a.size(); i += 2)
    {
        if (i + 1 < a.size())
        {
            comparisons++;
            if (a[i] > a[i + 1])
                std::swap(a[i], a[i + 1]);
            main_chain.push_back(std::make_pair(a[i + 1], a[i])); // (winner, loser)
        }
        else
            odd = a[i];
    }

    // split winners / losers
    for (size_t i = 0; i < main_chain.size(); ++i) {
        winners.push_back(main_chain[i].first);
        losers.push_back(main_chain[i].second);
    }
    if (odd != -1)
        losers.push_back(odd);

    // recurse on winners (deque)
    mergeInsertionSort(winners);

    // arrange losers using winners order
    std::vector<int> winners_vec(winners.begin(), winners.end());
    losers = arrangeLosers(main_chain, losers, winners_vec, odd);

    // Jacobsthal insertion order
    std::vector<int> insertion_order = JacobthalIndices((int)losers.size());
    genInsertionOrder(insertion_order, losers);

    // pre-insert first loser at the beginning (no comparison)
    if (insertion_order.size() > 1 && !losers.empty())
    {
        winners.insert(winners.begin(), losers[0]);
        losers[0] = -1; // mark consumed
    }

    // insert remaining by bounded binary search
    for (std::vector<int>::iterator it = insertion_order.begin();
         it != insertion_order.end(); ++it)
    {
        int index = *it;
        if (index < 0 || (size_t)index >= losers.size())
            continue;
        int val = losers[index];
        if (val == -1)
            continue;

        int lim = getIndex(winners, findFirstBySecond(main_chain, val)) - 1;
        if (lim > (int)winners.size() - 1) lim = (int)winners.size() - 1;

        std::deque<int>::iterator pos = winners.begin() + BinarySearch(winners, val, lim);
        winners.insert(pos, val);
        // (optional) losers[index] = -1;
    }

    a.swap(winners);
}
