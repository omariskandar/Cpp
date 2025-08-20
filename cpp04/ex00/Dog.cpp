#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "[Dog] constructed\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "[Dog] copy-constructed\n";
}

Dog& Dog::operator=(const Dog& rhs)
{
    if (this != &rhs)
        Animal::operator=(rhs);
    std::cout << "[Dog] copy-assigned\n";
    return *this;
}

Dog::~Dog()
{
    std::cout << "[Dog] destroyed\n";
}

void Dog::makeSound() const
{
    std::cout << "[Dog] Hw Hw!\n";
}
