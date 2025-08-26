/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 01:57:31 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/27 02:06:00 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <string>

template <typename T>
void printElement(T const & x) {
    std::cout << x << " ";
}

template <typename T>
void increment(T const & x) {
    std::cout << (x + 1) << " ";
}

int main() {
    int intArray[5] = {1, 2, 3, 4, 5};
    std::cout << "intArray: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    std::cout << "intArray incremented: ";
    iter(intArray, 5, increment<int>);
    std::cout << std::endl;

    std::string strArray[3] = {"hello", "world", "cpp07"};
    std::cout << "strArray: ";
    iter(strArray, 3, printElement<std::string>);
    std::cout << std::endl;

    float floatArray[4] = {1.1f, 2.2f, 3.3f, 4.4f};
    std::cout << "floatArray: ";
    iter(floatArray, 4, printElement<float>);
    std::cout << std::endl;

    return 0;
}
