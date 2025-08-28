/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:17:02 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/28 15:50:34 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {
    try {
        std::vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);

        std::list<int> l;
        l.push_back(5);
        l.push_back(15);
        l.push_back(25);

        std::vector<int>::iterator it1 = easyfind(v, 20);
        std::cout << "Found in vector: " << *it1 << std::endl;

        std::list<int>::iterator it2 = easyfind(l, 15);
        std::cout << "Found in list: " << *it2 << std::endl;

        easyfind(v, 50);
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}


