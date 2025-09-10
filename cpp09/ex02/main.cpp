/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:41:46 by oiskanda          #+#    #+#             */
/*   Updated: 2025/09/10 19:11:56 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <ctime>
#include <climits>

static bool parseIntStrictNoNegDup(const char* s, int& out, const std::vector<int>& existing)
{
    if (!s || !*s) return false;
    char* end = 0;
    long v = std::strtol(s, &end, 10);
    if (*end != '\0') return false;
    if (v < 0 || v > INT_MAX) return false;
    for (std::vector<int>::const_iterator it = existing.begin(); it != existing.end(); ++it)
        if (*it == (int)v) return false;
    out = (int)v;
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

static bool isSorted(const std::vector<int>& v)
{
    for (size_t i = 1; i < v.size(); ++i) if (v[i-1] > v[i]) return false;
    return true;
}
static bool isSorted(const std::deque<int>& d)
{
    for (size_t i = 1; i < d.size(); ++i) if (d[i-1] > d[i]) return false;
    return true;
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "Usage: " << (argc>0?argv[0]:"program") << " n1 n2 n3 ...\n";
        return 1;
    }

    std::vector<int> input;
    input.reserve(argc - 1);

    for (int i = 1; i < argc; ++i) {
        int x = 0;
        if (!parseIntStrictNoNegDup(argv[i], x, input)) {
            std::cerr << "Error\n";
            return 1;
        }
        input.push_back(x);
    }

    // Prepare both containers
    std::vector<int> v = input;
    std::deque<int>  d(input.begin(), input.end());

    // Vector run
    PmergeMe pm;
    comparisons = 0;
    clock_t t0 = clock();
    pm.mergeInsertionSort(v);
    clock_t t1 = clock();
    double vec_us = (double)(t1 - t0) * 1000000.0 / CLOCKS_PER_SEC;
    int vec_comp = comparisons;

    // Deque run
    comparisons = 0;
    clock_t t2 = clock();
    pm.mergeInsertionSort(d);
    clock_t t3 = clock();
    double deq_us = (double)(t3 - t2) * 1000000.0 / CLOCKS_PER_SEC;
    int deq_comp = comparisons;

    // Output
    printVector(input, "Before: ");
    printVector(v,     "After: ");
    std::cout << "Time to process a range of " << v.size()
              << " elements with std::vector : " << (long long)vec_us << " us\n";
    std::cout << "Comparisons (vector): " << vec_comp << "\n";

    // std::cout << "After (deque):  ";
    // for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); ++it) {
    //     if (it != d.begin()) std::cout << " ";
    //     std::cout << *it;
    // }
    // std::cout << std::endl;
    std::cout << "Time to process a range of " << d.size()
              << " elements with std::deque  : " << (long long)deq_us << " us\n";
    std::cout << "Comparisons (deque): " << deq_comp << "\n";

    if (!isSorted(v) || !isSorted(d)) {
        std::cerr << "ERROR: not sorted.\n";
        return 1;
    }
    return 0;
}
