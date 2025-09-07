/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:23:32 by oiskanda          #+#    #+#             */
/*   Updated: 2025/09/03 14:39:48 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <utility>

extern size_t comparisons;

int	checkNegative(std::vector <int> numbers);
std::vector<int> convertToVector(int argc, char **argv);
int	checkDuplicates(std::vector <int> numbers);
void checkSorted(std::vector <int> numbers);

inline bool cmp_less(int a, int b)
{
	++comparisons;
	return a < b;
}

template <typename Seq>
void build_main_and_pend(const Seq& nums, std::vector<int>& main_out, std::vector<int>& pend_out)
{
	main_out.clear();
	pend_out.clear();

	typename Seq::size_type i = 0;
	for(; i + 1 < nums.size(); i += 2)
	{
		int x = nums[i];
		int y = nums[i + 1];
		if (cmp_less(x, y))
		{
			int tmp = x;
			x = y;
			y = tmp;
		}
		main_out.push_back(x);
		pend_out.push_back(y);
	}
	if (i < nums.size())
		pend_out.push_back(nums[i]);
}

#endif
