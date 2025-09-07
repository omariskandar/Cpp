/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:40:09 by oiskanda          #+#    #+#             */
/*   Updated: 2025/09/05 18:21:07 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
    loadDatabase(dbFile);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& dbFile) {
    std::ifstream file(dbFile.c_str());
    if (!file)
        throw std::runtime_error("Error: could not open database file");

    std::string line;
    std::getline(file, line); // skip header
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, valueStr;
        if (!std::getline(ss, date, ',') || !std::getline(ss, valueStr))
            continue;
        double value = atof(valueStr.c_str());
        _db[date] = value;
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int y = std::atoi(date.substr(0,4).c_str());
    int m = std::atoi(date.substr(5,2).c_str());
    int d = std::atoi(date.substr(8,2).c_str());

    if (m < 1 || m > 12 || d < 1 || d > 31)
        return false;

    // February (with leap year check)
    if (m == 2) {
        bool leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
        if (d > (leap ? 29 : 28))
            return false;
    }

    // Months with 30 days
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
        return false;

    return true;
}

double BitcoinExchange::getRateForDate(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = _db.lower_bound(date);
    if (it == _db.end() || it->first != date) {
        if (it == _db.begin())
            throw std::runtime_error("Error: no earlier date available");
        --it;
    }
    return it->second;
}

void BitcoinExchange::processInput(const std::string& inputFile) {
    std::ifstream file(inputFile.c_str());
    if (!file)
        throw std::runtime_error("Error: could not open input file.");

    std::string line;
    std::getline(file, line); // skip header
    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string date, sep, valueStr;

        if (!(ss >> date >> sep >> valueStr) || sep != "|") {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        double value = atof(valueStr.c_str());
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        try {
            double rate = getRateForDate(date);
            std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}
