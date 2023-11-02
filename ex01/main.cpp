#include "Zombie.h"

int main() {
    int N = 1;
    Zombie *AlotZombie = zombieHorde(N, "Tom");
    for (int i = 0; i < N; i++) {
        AlotZombie[i].announce();
    }
    delete[] AlotZombie;
    return 0;
}
