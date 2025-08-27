/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:23:15 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/13 15:48:09 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <limits.h>
# include <string>
# include <iomanip>

class Contact
{
	public:
		Contact();

		std::string getFirstName();
		void setFirstName(std::string firstname);

		std::string getLastName();
		void setLastName(std::string lastname);

		std::string getNickName();
		void setNickName(std::string nickname);

		std::string getPhone();
		void setPhone(std::string phone);

		std::string getSecret();
		void setSecret(std::string secret);

	private:
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _phone;
		std::string _secret;
};

#endif
