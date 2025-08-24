/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 23:26:35 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/24 23:32:20 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "Identify.hpp"

int main() {
    std::srand(std::time(0));  // ✅ seed once here
    for (int i = 0; i < 5; i++) {
        Base* obj = generate();
        identify(obj);
        identify(*obj);
        delete obj;
        std::cout << "----" << std::endl;
    }
    return 0;
}
