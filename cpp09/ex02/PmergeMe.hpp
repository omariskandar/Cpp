/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:23:32 by oiskanda          #+#    #+#             */
/*   Updated: 2025/09/03 02:46:27 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <utility>

int	checkNegative(std::vector <int> numbers);
std::vector<int> convertToVector(int argc, char **argv);
int	checkDuplicates(std::vector <int> numbers);
void checkSorted(std::vector <int> numbers);

std::vector<int> makingPairs(std::vector<int> nums);

#endif
