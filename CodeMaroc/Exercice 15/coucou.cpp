#include <iostream>

const int nbTurns = 10;

int main() {
    int i = 0;
    while (i < nbTurns) {
        std::cout << "Bonjour numero : " << i + 1 << std::endl;
        i++;
    }
    
    return 0;
}