/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:45:24 by hfalati           #+#    #+#             */
/*   Updated: 2025/09/23 15:05:28 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
    private:
        Contact contacts[8];
        int count;
        int nextindex;
    
    public:
        PhoneBook();
        ~PhoneBook();

        void addcontact(const Contact& c);
        void showcontacts() const;
        void displaycontact(int index) const;
        int getCount() const;
};

#endif