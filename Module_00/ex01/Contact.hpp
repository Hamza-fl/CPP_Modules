#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

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