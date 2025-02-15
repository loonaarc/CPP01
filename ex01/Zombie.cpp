#include "Zombie.hpp"

Zombie::~Zombie() {
    std::cout << name << " says byebye!\n";
}

void Zombie::setName(std::string name) {
    this->name = name;
}

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}