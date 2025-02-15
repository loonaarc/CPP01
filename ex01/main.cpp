#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void) {
    int n = 5;

    Zombie* horde = zombieHorde(n, "One of them");
    for (int i = 0; i < n; i++) {
        horde[i].announce();
    }
    delete[] horde;
    horde = NULL;
}