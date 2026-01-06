/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:56:46 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/05 20:09:49 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class PhoneBook
{
	private:
		Contact mi7fada[8];
		int	total_contact;
		int index;
	public:
		PhoneBook();
		void add_to_mi7fada();
		void display_all_contacts();
		void display_contact(int index);
		void search_from_mi7fada();
};

#endif
