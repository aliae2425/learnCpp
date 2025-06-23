#include <iostream>

bool isEven(int number) {
    return number % 2 == 0;
}

int main(){
    int number;
    std::cout << "Entrez un nombre entier: ";
    std::cin >> number;

    std::cout << "Le nombre " << number << (isEven(number) ? " est pair." : " est impair.") << std::endl;
    return 0;
}