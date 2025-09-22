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

bool checkEmpty(const char* prompt, std::string& out){
    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, out))
            return false;
        if (!out.empty())
            return true;
        std::cout << "Cannot be empty\n";
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