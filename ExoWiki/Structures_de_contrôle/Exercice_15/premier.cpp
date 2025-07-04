#include <iostream>

bool premier(int n) {
    if (n <= 1) return 0; // 0 and 1 are not prime numbers
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return 0; // n is divisible by i, hence not prime
    }
    return 1; // n is prime
}

int main() {
    int n;
    std::cout << "Entrez un nombre entier positif: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Veuillez entrer un nombre entier positif." << std::endl;
        return 1; // Exit with an error code
    }

    std::cout << n << (premier(n)?" est": "n'est pas") << " un nombre premier." << std::endl;

    return 0;
}