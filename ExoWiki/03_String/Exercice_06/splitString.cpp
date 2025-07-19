#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> splitString(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    for (char c : str) {
        if (c == delimiter) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        } else {
            token += c;
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    std::string input;
    char delimiter;

    std::cout << "Entrez une chaîne de caractères : ";
    std::getline(std::cin, input);
    std::cout << "Entrez le délimiteur : ";
    std::cin.get(delimiter);

    std::vector<std::string> result = splitString(input, delimiter);

    std::cout << "Les sous-chaînes sont :" << std::endl;
    for (const auto& token : result) {
        std::cout << token << std::endl;
    }

    return 0;
}
