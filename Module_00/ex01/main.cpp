/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:45:16 by hfalati           #+#    #+#             */
/*   Updated: 2025/09/23 15:03:45 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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
                continue;
            }
        }
        else if (cmd == "SEARCH"){
            phonebook.showcontacts();
            if (phonebook.getCount() == 0) continue;
            std::cout << "Enter index to display: ";
            std::string idxStr;
            if (!std::getline(std::cin, idxStr)) continue;
            if (!isNumber(idxStr)) {
                std::cout << "Invalid input\n";
                continue;
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