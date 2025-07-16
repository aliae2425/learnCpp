#include <iostream>
#include <string>

std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    for (char& c : lowerStr) {
        if (c >= 'A' && c <= 'Z') {
            c += ('a' - 'A'); // Convert uppercase to lowercase
        }
    }
    return lowerStr;
}

int main() {
    std::string input;
    std::cout << "Entrez une chaîne de caractères : ";
    std::getline(std::cin, input);

    std::string lowerCaseInput = toLower(input);
    std::cout << "La chaîne en minuscules est : " << lowerCaseInput << std::endl;

    return 0;
}