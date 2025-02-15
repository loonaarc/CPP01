#include "Zombie.hpp"

void    randomChump(std::string name);
Zombie* newZombie(std::string name);


int main(void) {
    //Zombie on stack:
    randomChump("StackZombie");

    //Zombie on heap:
    Zombie *heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;
    heapZombie = NULL;
}