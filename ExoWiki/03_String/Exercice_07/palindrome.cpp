#include <iostream>
#include <string>

bool isPalindrome(const std::string& str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    std::string input;
    std::cout << "Entrez une chaîne de caractères : ";
    std::getline(std::cin, input);

    if (isPalindrome(input)) {
        std::cout << "La chaîne est un palindrome." << std::endl;
    } else {
        std::cout << "La chaîne n'est pas un palindrome." << std::endl;
    }

    return 0;
}
