#include <iostream>

int cube(int n) {
    return n * n * n;
}

int sumOfCubes(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += cube(i);
    }
    return sum;
}

int main() {
    int n;
    std::cout << "Entrez un nombre entier positif: ";
    std::cin >> n;

    if (n < 1) {
        std::cout << "Veuillez entrer un nombre entier positif." << std::endl;
        return 1; // Exit with an error code
    }

    int result = sumOfCubes(n);
    std::cout << "La somme des cubes des entiers de 1 a " << n << " est: " << result << std::endl;

    return 0;
}