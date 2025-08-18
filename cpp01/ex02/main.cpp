/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 01:12:21 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/19 01:16:19 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() 
{
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;
    std::cout << "Address of string variable : " << &brain     << std::endl;
    std::cout << "Address held by stringPTR : " << stringPTR << std::endl;
    std::cout << "Address held by stringREF : " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "Value of string variable : " << brain     << std::endl;
    std::cout << "Value pointed to by PTR : " << *stringPTR << std::endl;
    std::cout << "Value pointed to by REF : " << stringREF << std::endl;

    return 0;
}