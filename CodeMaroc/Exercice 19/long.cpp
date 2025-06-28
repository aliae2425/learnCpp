#include <iostream>
#include <vector>
#include <string>   


int main(){
    std::string word;
    std::cout << "Entrez un nombre entier positif: ";
    std::cin >> word;

    std::cout << "le nombre est composer de " << word.length() << " chiffres." << std::endl;

    return 0;
}