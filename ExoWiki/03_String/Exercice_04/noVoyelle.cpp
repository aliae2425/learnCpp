#include <iostream>
#include <string>

std::string removeVowels(const std::string& str) {
    std::string result;
    for (char c : str) {
        if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
              c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')) {
            result += c;
        }
    }
    return result;
}

int main() {
    std::string input;
    std::cout << "Entrez une chaîne de caractères : ";
    std::getline(std::cin, input);

    std::string noVowelInput = removeVowels(input);
    std::cout << "La chaîne sans voyelles est : " << noVowelInput << std::endl;

    return 0;
}