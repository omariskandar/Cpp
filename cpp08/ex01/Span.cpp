/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:59:51 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/28 16:35:02 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _capacity(0) {}

Span::Span(unsigned int N) : _capacity(N) {}

Span::Span(const Span& other) : _capacity(other._capacity), _numbers(other._numbers) {}

Span& Span::operator=(const Span& rhs) {
    if (this != &rhs) {
        _capacity = rhs._capacity;
        _numbers = rhs._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int nb) {
    if (_numbers.size() >= _capacity)
        throw std::overflow_error("Span is full");
    _numbers.push_back(nb);
}

int Span::shortestSpan() {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size(); i++) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan() {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return max - min;
}

