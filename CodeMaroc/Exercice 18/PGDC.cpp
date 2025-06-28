#include <iostream>

int PGDC(int a, int b) {
    if (b == 0) {
        return a;
    }
    return PGDC(b, a % b);
}

int main() {
    int a, b;
    std::cout << "Entrez deux entiers pour calculer leur PGDC: ";
    std::cin >> a >> b;
    if (a < 0 || b < 0) {
        std::cout << "Veuillez entrer des entiers positifs." << std::endl;
    } else {
        int result = PGDC(a, b);
        std::cout <<
            "Le PGDC de " << a << " et " << b << " est: " << result << std::endl;
    } 
    return 0;
}
