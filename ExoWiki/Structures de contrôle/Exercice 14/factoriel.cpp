#include <iostream>

int factorial(int n) {
    if (n <= 1) {
        return 1; // Base case: 0! = 1 and 1! = 1
    } else {
        return n * factorial(n - 1); // Recursive case
    }
}

int main() {
    int n;
    std::cout << "Entrez un nombre entier positif pour calculer sa factorielle: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Veuillez entrer un nombre entier positif." << std::endl;
    } else {
        int result = factorial(n);
        std::cout << "La factorielle de " << n << " est: " << result << std::endl;
    }

    return 0;
}