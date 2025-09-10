/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:09:30 by oiskanda          #+#    #+#             */
/*   Updated: 2025/09/10 19:02:12 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

extern int comparisons;
class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe &operator=(const PmergeMe& other);
		~PmergeMe();
		void mergeInsertionSort(std::vector<int>& a);
		void mergeInsertionSort(std::deque<int>&  a);


};

#endif
