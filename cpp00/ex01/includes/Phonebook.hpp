/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:23:17 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/13 16:00:19 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <cstring>
# include <iomanip>
# include <iostream>
# include <limits>
# include <sstream>

class PhoneBook
{
  public:
	PhoneBook();
	void add();
	void search();
	void display();

	int index;

  private:
	static int counter;
	Contact _contacts[8];
};

#endif
