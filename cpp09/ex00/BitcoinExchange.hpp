/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:40:40 by oiskanda          #+#    #+#             */
/*   Updated: 2025/09/10 18:12:37 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>

class BitcoinExchange {
public:
    BitcoinExchange(const std::string& dbFile);
    ~BitcoinExchange();

    void processInput(const std::string& inputFile);

private:
    std::map<std::string, double> _db;

    void loadDatabase(const std::string& dbFile);
    bool isValidDate(const std::string& date) const;
    double getRateForDate(const std::string& date) const;
};

#endif
