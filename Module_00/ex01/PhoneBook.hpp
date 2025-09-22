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