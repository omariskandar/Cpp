/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:23:32 by oiskanda          #+#    #+#             */
/*   Updated: 2025/09/01 17:30:48 by oiskanda         ###   ########.fr       */
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
std::pair<std::vector<int>, std::vector<int> >
slpitToPairs(std::vector <int>& numbers);
#endif
