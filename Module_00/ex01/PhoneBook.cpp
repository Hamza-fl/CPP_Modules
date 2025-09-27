/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:45:19 by hfalati           #+#    #+#             */
/*   Updated: 2025/09/23 11:45:20 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): count(0), nextindex(0) {}
PhoneBook::~PhoneBook() {}

int PhoneBook::getCount() const { return count; }

void PhoneBook::addcontact(const Contact& c){
    contacts[nextindex] = c;
    nextindex = (nextindex + 1) % 8;
    if (count < 8) ++count;
}

void PhoneBook::displaycontact(int index) const {
    if (index < 0 || index >= count){
        std::cout << "Invalid index\n";
        return;
    }
    const Contact& c = contacts[index];
    std::cout << "First name: " << c.getfirstname() << '\n';
    std::cout << "Last name: " << c.getlastname() << '\n';
    std::cout << "Nickname: " << c.getnickname() << '\n';
    std::cout << "Phone number: " << c.getphonenumber() << '\n';
    std::cout << "Darkest secret: " << c.getdarkestsecret() << '\n';
}

std::string formatField(const std::string& text) {
    if (text.length() > 10) {
        return text.substr(0, 9) + ".";
    }
    std::string result = text;
    while (result.length() < 10) {
        result = " " + result;
    }
    return result;
}

void PhoneBook::showcontacts() const {
    std::cout << "     Index|First Name| Last Name|  Nickname\n";
    
    for (int i = 0; i < count; i++) {
        std::stringstream ss;
        ss << i;
        std::string indexStr = ss.str();
        std::cout << formatField(indexStr) << "|"
                  << formatField(contacts[i].getfirstname()) << "|"
                  << formatField(contacts[i].getlastname()) << "|"
                  << formatField(contacts[i].getnickname()) << "\n";
    }
}