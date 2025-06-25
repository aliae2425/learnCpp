#include <iostream>

bool product(int a, int b) {
    return (a * b)<0;
}

bool isNull(int a, int b) {
    return a == 0 || b == 0;
}

int main() {
    int a, b;
    std::cout << "Entrez deux nombres: ";
    std::cin >> a >> b;

    if (isNull(a, b)) {
        std::cout << "L'un des nombres est nul." << std::endl;
        return 0;
    }

    std::cout << "Le produit de " << a << " et " << b << " est " 
              << (product(a, b) ? "négatif." : "positif") << std::endl;
    return 0;
}