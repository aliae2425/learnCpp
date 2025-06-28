#include <iostream>

int main() {
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;

    if (age < 6){
        std::cout << "Age invalide, veuillez entrer un âge supérieur ou égal à 6." << std::endl;
    }else if (age <= 7){
        std::cout << "Bienvenu chez les poussin" << std::endl;
    }else if (age <= 9){
        std::cout << "Bienvenu chez les pupilles" << std::endl;
    }else if (age <= 11){
        std::cout << "Bienvenu chez les minimes" << std::endl;
    }else{
        std::cout << "Bienvenu chez les cadets" << std::endl;
    }
    return 0;
}