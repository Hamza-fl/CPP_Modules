#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <sstream>

bool isNumber(const std::string& str) {
    if (str.empty()) return false;
    for (size_t i = 0; i < str.size(); i++) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

int main(){
    PhoneBook phonebook;
    std::string cmd;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, cmd))
            break;
        if (cmd == "ADD")
        {
            Contact c;
            if (c.filltable()) {
                phonebook.addcontact(c);
                std::cout << "Contact added\n";
            }else {
                std::cout << "\nsomething faill\n";
            }
        }
        else if (cmd == "SEARCH"){
            phonebook.showcontacts();
            if (phonebook.getCount() == 0) continue;
            std::cout << "Enter index to display: ";
            std::string idxStr;
            if (!std::getline(std::cin, idxStr)) break;
            if (!isNumber(idxStr)) {
                std::cout << "Invalid input\n";
                break;
            }
            int idx = std::atoi(idxStr.c_str());
            phonebook.displaycontact(idx);
        }
        else if (cmd == "EXIT") {
            break;
        }
        else
            std::cout << "Unknown command, please use ADD, SEARCH or EXIT.\n";
    }
    return 0;
}