#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>


int main(){
    srand(time(nullptr)); // Initialize random seed
    int min = rand() % 100; // Random number between 0 and 99
    int max = min + (rand() % 100); // Random number between min and min+99
    

    int guess;
    std::cout << "je pense a un nombre entre 0 et 200" << std::endl;
    std::cout << "essaye de le deviner!" << std::endl;

    std::cin >> guess;
    if (guess < min || guess > max) {
        std::cout << "perdu! le nombre etait entre " << min << " et " << max << std::endl;
    } else {
        std::cout << "bravo! tu as devine le nombre!" << std::endl;
        std::cout << "le nombre etait entre " << min << " et " << max << std::endl;
    }
    return 0;
}