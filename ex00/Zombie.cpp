#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name){
}

Zombie::~Zombie() {
    std::cout << name << " says byebye!\n";
}

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}