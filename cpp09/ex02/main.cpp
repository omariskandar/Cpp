/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:41:46 by oiskanda          #+#    #+#             */
/*   Updated: 2025/09/03 14:33:16 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main() {
    int raw[] = {30,49, 60,1, 31,29, 42,46, 13,8, 5};
    std::vector<int> nums(raw, raw + sizeof(raw)/sizeof(raw[0]));

    std::vector<int> main_chain, pend_chain;
    comparisons = 0;
    build_main_and_pend(nums, main_chain, pend_chain);

    std::cout << "Main (a): ";
    for (size_t k = 0; k < main_chain.size(); ++k) std::cout << main_chain[k] << " ";
    std::cout << "\nPend (b + extra): ";
    for (size_t k = 0; k < pend_chain.size(); ++k) std::cout << pend_chain[k] << " ";
    std::cout << "\nComparisons: " << comparisons << "\n";
}

