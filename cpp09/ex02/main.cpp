/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:41:46 by oiskanda          #+#    #+#             */
/*   Updated: 2025/09/10 18:30:22 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <ctime>
#include <climits>

static bool isSorted(const std::vector<int>& vec)
{
    if (vec.size() <= 1)
        return true;

    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i - 1] > vec[i])
            return false;
    }
    return true;
}

static bool parseIntStrict(const char* s, int& out, const std::vector<int>& existing)
{
    if (!s || !*s) return false;

    char* end = 0;
    long v = std::strtol(s, &end, 10);

    // must consume whole string
    if (*end != '\0') return false;

    // must fit in int
    if (v < INT_MIN || v > INT_MAX) return false;

    // must be non-negative
    if (v < 0) return false;

    // must not be duplicate
    for (std::vector<int>::const_iterator it = existing.begin();
         it != existing.end(); ++it)
    {
        if (*it == (int)v)
            return false; // duplicate found
    }

    out = static_cast<int>(v);
    return true;
}

static void printVector(const std::vector<int>& v, const char* label)
{
    std::cout << label;
    for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
        if (it != v.begin()) std::cout << " ";
        std::cout << *it;
    }
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "Usage: " << (argc > 0 ? argv[0] : "program") << " n1 n2 n3 ...\n";
        return 1;
    }

    std::vector<int> data;
    data.reserve(argc - 1);

	for (int i = 1; i < argc; ++i) {
		int val = 0;
		if (!parseIntStrict(argv[i], val, data)) {
			std::cerr << "Error\n";
			return 1;
		}
		data.push_back(val);
	}

	if (isSorted(data))
    	std::cout << "Vector is sorted\n";
	else
	{
		printVector(data, "Before: ");

		comparisons = 0;
		PmergeMe pm;
		pm.mergeInsertionSort(data);

		printVector(data, "After:  ");
		std::cout << "Comparisons: " << comparisons << std::endl;

		for (size_t i = 1; i < data.size(); ++i) {
			if (data[i-1] > data[i]) {
				std::cerr << "ERROR: result is not sorted.\n";
				return 1;
			}
		}
	}
    return 0;
}
