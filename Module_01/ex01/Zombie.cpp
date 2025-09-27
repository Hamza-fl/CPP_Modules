#include "Zombie.hpp"

Zombie::Zombie() : name("") {}

Zombie::Zombie(const std::string& n) : name(n) {}

Zombie::~Zombie() {
    std::cout << name << " is destroyed" << std::endl;
}

void Zombie::announce(void) const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& n) {
    name = n;
}
