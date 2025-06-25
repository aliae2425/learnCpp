#include <iostream>

int main(){
    int tableInput;
    std::cout << "Entrez un nombre pour afficher sa table de multiplication: ";
    std::cin >> tableInput;

    if (tableInput < 0) {
        std::cout << "Veuillez entrer un nombre entier positif." << std::endl;
    } else {
        std::cout << "Table de multiplication de " << tableInput << ":" << std::endl;
        for (int i = 1; i <= 10; ++i) {
            std::cout << tableInput << " x " << i << " = " << tableInput * i << std::endl;
        }
    }
    return 0;
}