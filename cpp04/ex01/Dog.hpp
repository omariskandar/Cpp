/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:44:17 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 18:44:32 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& rhs);
    virtual ~Dog();

    virtual void makeSound() const;  // override
    // Helpers to test deep copy
    void setIdea(int idx, const std::string& idea);
    const std::string& getIdea(int idx) const;

private:
    Brain* brain; // dynamically allocated
};

#endif // DOG_HPP
