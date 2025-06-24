#include <iostream>
#include <cmath>

int main() {
    int a;
    std::cout << "Entrez un nombre: ";
    std::cin >> a;
    std::cout << "La valeur absolue de " << a << " est " << std::abs(a) << std::endl;
    // std::cout << "La valeur absolue de " << a << " est " << (a < 0 ? -a : a) << std::endl;
    return 0;
}