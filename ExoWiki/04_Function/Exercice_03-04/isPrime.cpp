#include <iostream>
#include <vector>

const std::vector<std::pair<int, bool>> TEST_Exercice03 = {{2, true}, {3, true}, {6, false}, {7, true}, {10, false}, {11, true}};
const std::vector<std::pair<int, int>> TEST_Exercice04 = {{2, 3}, {4,7}, {6, 13}, {10, 29}};

bool isPrime(int n) {
    if (n <= 1) return false; // 0 and 1 are not prime numbers
    for (int i = 2; i * i <= n; ++i) { // Check divisibility up to the square root of n
        if (n % i == 0) return false; // If n is divisible by any number other than 1 and itself, it's not prime
    }
    return true; // If no divisors found, n is prime
}

int findNPrime(int n){
    int count = 0;
    int num = 2; // Start checking for prime from 2
    while (count < n) {
        if (isPrime(num)) {
            count++;
        }
        num++;
    }
    return num - 1; // Return the last found prime number
}

int main() {
    std::cout << "Exercice 03 - isPrime function tests:" << std::endl;
    int testCount = 0;
    for (const auto& test : TEST_Exercice03) {
        if(isPrime(test.first) == test.second) {
            std::cout << "Test " << ++testCount << ": Passed for " << test.first << std::endl;
        } else {
            std::cout << "Test " << ++testCount << ": Failed for " << test.first << std::endl;
        }
    }
    if (testCount == TEST_Exercice03.size()) {
        std::cout << "All tests passed!" << std::endl;
    } else {
        std::cout << (TEST_Exercice03.size() - testCount) << " tests failed." << std::endl;
    }

    std::cout << "\nExercice 04 - isPrime function tests with pairs:" << std::endl;
    testCount = 0;
    for (const auto& test : TEST_Exercice04) {
        if(findNPrime(test.first) == test.second) { // Assuming even numbers are not prime except 2
            std::cout << "Test " << ++testCount << ": Passed for " << test.first << std::endl;
        } else {
            std::cout << "Test " << ++testCount << ": Failed for " << test.first << std::endl;
        }
    }
    if (testCount == TEST_Exercice04.size()) {
        std::cout << "All tests passed!" << std::endl;
    } else {
        std::cout << (TEST_Exercice04.size() - testCount) << " tests failed." << std::endl;
    }
    return 0;
}