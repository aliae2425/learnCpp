#include <iostream>

bool premier(int n) {
    if (n <= 1) return false; // 0 and 1 are not prime numbers
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false; // n is divisible by i, hence not prime
    }
    return true; // n is prime
}

int neniemePrime(int N) {
    int prime = 0;
    for (int i = 2; i <= N; ++i) {
        if (premier(i)) {
            prime = i; // Store the last prime number found
        }
    }
    return prime;
}

int main() {
    int N;
    std::cout << "Entrez un nombre entier positif N: ";
    std::cin >> N;

    if (N < 0) {
        std::cout << "Veuillez entrer un nombre entier positif." << std::endl;
        return 1; // Exit with an error code
    }

    int lastPrime = neniemePrime(N);
    if (lastPrime > 0) {
        std::cout << "Le dernier nombre premier avant " << N << " est: " << lastPrime << std::endl;
    } else {
        std::cout << "Aucun nombre premier trouvé avant " << N << "." << std::endl;
    }

    return 0;
}

