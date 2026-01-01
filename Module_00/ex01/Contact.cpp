/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:45:05 by hfalati           #+#    #+#             */
/*   Updated: 2025/09/23 11:45:06 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>


void Contact::setfirstname(const std::string& s) {firstName = s;}
void Contact::setlastname(const std::string& s) {lastName = s;}
void Contact::setnickname(const std::string& s) {nickname = s;}
void Contact::setphonenumber(const std::string& s) {phoneNumber = s;}
void Contact::setdarkestsecret(const std::string& s) {darkestSecret = s;}

const std::string& Contact::getfirstname() const {return firstName; }
const std::string& Contact::getlastname() const {return lastName; }
const std::string& Contact::getnickname() const {return nickname; }
const std::string& Contact::getphonenumber() const {return phoneNumber; }
const std::string& Contact::getdarkestsecret() const {return darkestSecret; }

bool Contact::isEmpty() const {
    return firstName.empty() || lastName.empty() || nickname.empty()
        || phoneNumber.empty() || darkestSecret.empty();
}

bool isprintable(std::string& str){
    for (size_t i = 0; i < str.length(); i++){
        if (!std::isprint(str[i]))
            return false;
    }
    return true;
}

bool checkEmpty(const char* prompt, std::string& out){
    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, out))
            return false;
        if (out.empty()){
            std::cout << "Cannot be empty\n";
            continue;
        }
        if (!isprintable(out)){
            std::cout << "Only printable characters\n";
            continue;
        }
        return true;
    }
}

bool Contact::filltable(){
    std::string tmp;
    if (!checkEmpty("Fist name: ", tmp)) return false;
    setfirstname(tmp);
    if (!checkEmpty("Last name: ", tmp)) return false;
    setlastname(tmp);
    if (!checkEmpty("Nickname: ", tmp)) return false;
    setnickname(tmp);
    if(!checkEmpty("Phone number: ", tmp)) return false;
    setphonenumber(tmp);
    if (!checkEmpty("darckest secret: ", tmp)) return false;
    setdarkestsecret(tmp);
    return true;
}