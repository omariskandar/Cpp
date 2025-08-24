/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 23:12:48 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/24 23:12:54 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data;
    data.number = 42;
    data.text = "Hello Serialization!";

    std::cout << "Original Data:" << std::endl;
    std::cout << "  number: " << data.number << std::endl;
    std::cout << "  text: " << data.text << std::endl;
    std::cout << "  address: " << &data << std::endl;

    // Serialize
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value (uintptr_t): " << raw << std::endl;

    // Deserialize
    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << ptr << std::endl;
    std::cout << "  number: " << ptr->number << std::endl;
    std::cout << "  text: " << ptr->text << std::endl;

    return 0;
}
