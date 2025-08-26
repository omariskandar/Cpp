/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 02:13:10 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/27 02:13:11 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
private:
    T* _data;
    unsigned int _size;

public:
    // Default constructor
    Array() : _data(NULL), _size(0) {}

    // Constructor with size
    Array(unsigned int n) : _data(new T[n]()), _size(n) {}

    // Copy constructor
    Array(const Array& other) : _data(NULL), _size(0) {
        *this = other;
    }

    // Assignment operator
    Array& operator=(const Array& rhs) {
        if (this != &rhs) {
            delete[] _data;
            _size = rhs._size;
            if (_size > 0) {
                _data = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    _data[i] = rhs._data[i];
            } else {
                _data = NULL;
            }
        }
        return *this;
    }

    // Destructor
    ~Array() {
        delete[] _data;
    }

    // Operator[] with bounds check
    T& operator[](unsigned int index) {
        if (index >= _size)
            throw std::out_of_range("Index out of range");
        return _data[index];
    }

    // Const version of operator[]
    const T& operator[](unsigned int index) const {
        if (index >= _size)
            throw std::out_of_range("Index out of range");
        return _data[index];
    }

    // Size function
    unsigned int size() const {
        return _size;
    }
};

#endif
