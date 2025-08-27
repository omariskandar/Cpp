/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:22:36 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/13 16:00:33 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Contact.hpp"

Contact::Contact() {}

std::string Contact::getFirstName()
{
	return this->_firstname;
}
void Contact::setFirstName(std::string firstname)
{
	this->_firstname = firstname;
}

std::string Contact::getLastName()
{
	return this->_lastname;
}
void Contact::setLastName(std::string lastname)
{
	this->_lastname = lastname;
}

std::string Contact::getNickName()
{
	return this->_nickname;
}
void Contact::setNickName(std::string nickname)
{
	this->_nickname = nickname;
}

std::string Contact::getPhone()
{
	return this->_phone;
}
void Contact::setPhone(std::string phone)
{
	this->_phone = phone;
}

std::string Contact::getSecret()
{
	return this->_secret;
}
void Contact::setSecret(std::string secret)
{
	this->_secret = secret;
}
