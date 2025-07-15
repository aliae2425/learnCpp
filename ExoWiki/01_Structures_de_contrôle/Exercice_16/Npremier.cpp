#include <iostream>
#include <vector>

bool premier(int n) {
    if (n <= 1) return false; // 0 and 1 are not prime numbers
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false; // n is divisible by i, hence not prime
    }
    return true; // n is prime
}

int countPrimes(int N, std::vector<int>& primes) {
    int count = 0;
    for (int i = 2; i <= N; ++i) {
        if (premier(i)) {
            primes.push_back(i); // Store the prime number
            count++;
        }
    }
    return count;
}

int main() {
    int N;
    std::vector<int> primes;
    std::cout << "Entrez un nombre entier positif N: ";
    std::cin >> N;

    if (N < 0) {
        std::cout << "Veuillez entrer un nombre entier positif." << std::endl;
        return 1; // Exit with an error code
    }

    std::cout << "Le nombre de nombres premiers jusqu'à " << N << " est: " << countPrimes(N, primes) << std::endl;
    std::cout << "Les nombres premiers jusqu'à " << N << " sont: ";
    for (size_t i = 0; i < primes.size(); ++i) {
        std::cout << primes[i];
        if (i < primes.size() - 1) {
            std::cout << ", ";
        }
    }
    
    return 0;
}