/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 02:13:20 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/27 02:13:22 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
    try {
        std::cout << "== Test with int ==" << std::endl;
        Array<int> intArray(5);
        for (unsigned int i = 0; i < intArray.size(); i++)
            intArray[i] = i * 10;
        for (unsigned int i = 0; i < intArray.size(); i++)
            std::cout << intArray[i] << " ";
        std::cout << std::endl;

        std::cout << "== Test with std::string ==" << std::endl;
        Array<std::string> strArray(3);
        strArray[0] = "hello";
        strArray[1] = "world";
        strArray[2] = "!";
        for (unsigned int i = 0; i < strArray.size(); i++)
            std::cout << strArray[i] << " ";
        std::cout << std::endl;

        std::cout << "== Test copy constructor ==" << std::endl;
        Array<int> copyArray(intArray);
        for (unsigned int i = 0; i < copyArray.size(); i++)
            std::cout << copyArray[i] << " ";
        std::cout << std::endl;

        std::cout << "== Test assignment ==" << std::endl;
        Array<int> assignedArray;
        assignedArray = intArray;
        for (unsigned int i = 0; i < assignedArray.size(); i++)
            std::cout << assignedArray[i] << " ";
        std::cout << std::endl;

        std::cout << "== Test out of range ==" << std::endl;
        std::cout << intArray[10] << std::endl; // should throw
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
