This repository contains my solutions for the 42 C++ Piscine modules.
Each module builds progressively on OOP, templates, polymorphism, STL, and advanced C++ concepts.

🚀 Modules Overview
✅ CPP Module 00 – Basics

Topics: namespaces, classes, member functions, static, const, iostreams, Orthodox Canonical Form.

Key projects:

megaphone: simple argc/argv project.

PhoneBook: store up to 8 contacts, handle ADD, SEARCH, EXIT.

Zombie exercises: heap vs stack allocation.

Pointers & references demo.

✅ CPP Module 01 – Memory & Pointers

Topics: new/delete, references, switch, member function pointers.

Key projects:

Zombies horde (Zombie* zombieHorde(int N, std::string)).

Pointers vs references (stringPTR, stringREF).

Weapon/HumanA/HumanB classes.

File replacement (s1 → s2 in <filename>.replace).

Harl complaining system (levels DEBUG, INFO, WARNING, ERROR).

✅ CPP Module 02 – Ad-hoc Polymorphism, Operators

Topics: fixed-point numbers, operator overloading, static functions.

Key projects:

Fixed class (conversion between int, float, raw bits).

Operator overloads: comparison, arithmetic, increment/decrement.

Point class + bsp() (point-in-triangle algorithm).

✅ CPP Module 03 – Inheritance

Topics: simple inheritance, base class construction/destruction order.

Key projects:

ClapTrap, ScavTrap, FragTrap, DiamondTrap.

Show how constructors/destructors chain in multiple inheritance.

✅ CPP Module 04 – Polymorphism & Abstract Classes

Topics: virtual functions, destructors, abstract base classes, interfaces.

Key projects:

Animal, Dog, Cat with makeSound().

Brain deep copies inside Dog/Cat.

Abstract AAnimal class (cannot be instantiated).

WrongAnimal/WrongCat demo (no virtual → wrong behavior).

✅ CPP Module 05 – Exceptions

Topics: exception handling, nested classes, operator overloading.

Key projects:

Bureaucrat (grades, exceptions GradeTooHigh/TooLow).

Form (signing/execution conditions).

Derived forms:

ShrubberyCreationForm

RobotomyRequestForm

PresidentialPardonForm

Intern that generates forms (factory pattern).

✅ CPP Module 06 – Casts & RTTI

Topics: static_cast, reinterpret_cast, const_cast, dynamic_cast.

Key projects:

ScalarConverter (literal → char/int/float/double).

Serializer (pointer → integer → pointer).

Base/A/B/C type identification with dynamic_cast.

✅ CPP Module 07 – Templates

Topics: function/class templates, iterators, operator overloads.

Key projects:

iter() function template (apply function to array).

Array<T> class template (safe array with bounds checking).

Template programming with user-defined classes.

✅ CPP Module 08 – STL Basics

Topics: containers (vector, list, map), iterators, algorithms.

Key projects:

easyfind function template (find element in any container).

Span class (store numbers, compute shortest/longest span).

MutantStack (stack with iterator support).

✅ CPP Module 09 – STL Advanced

Topics: parsing, algorithms, real-world problems.

Key projects:

BitcoinExchange (parse database, convert values).

RPN (Reverse Polish Notation calculator).

PmergeMe (merge-insert sort with deque & vector).
