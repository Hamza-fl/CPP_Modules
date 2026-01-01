/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:45:12 by hfalati           #+#    #+#             */
/*   Updated: 2025/09/23 15:05:09 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

class Contact{
	private :
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

	public :
		const std::string& getfirstname() const;
		const std::string& getlastname() const;
		const std::string& getnickname() const;
		const std::string& getphonenumber() const;
		const std::string& getdarkestsecret() const;

		void setfirstname(const std::string& s);
		void setlastname(const std::string& s);
		void setnickname(const std::string& s);
		void setphonenumber(const std::string& s);
		void setdarkestsecret(const std::string& s);

		bool filltable();
		bool isEmpty() const;
};


#endif