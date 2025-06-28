#include <iostream>

int sum(int n){
    if (n == 0) {
        return 0;
    } else {
        return n + sum(n - 1);
    }
}

int main() {
    int n;
    std::cout << "Entrez un nombre entier positif: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Veuillez entrer un nombre entier positif." << std::endl;
    } else {
        int result = sum(n);
        std::cout << "La somme des entiers de 1 à " << n << " est: " << result << std::endl;
    }

    return 0;
}