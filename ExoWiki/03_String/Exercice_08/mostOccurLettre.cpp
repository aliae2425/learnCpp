#include <iostream>
#include <string>
#include <vector>

void displayLetterCount(const std::vector<std::pair<char, int>>& letterCount) {
    for (const auto& pair : letterCount) {
        if (pair.second > 0) {
            std::cout << "Letter '" << pair.first << "': " << pair.second << " times\n";
        }
    }
}

int getMostOccurLetter(const std::string& str) {
    std::vector<std::pair<char, int>> letterCount(26, {'a', 0}); // 26 letters in the alphabet
    
    // Initialize each pair with correct letter
    for (int i = 0; i < 26; ++i) {
        letterCount[i].first = 'a' + i;
        letterCount[i].second = 0;
    }
    
    int maxCount = 0;

    for (char c : str) {
        if (c != ' ') {
            for (int i = 0; i < 26; ++i) {
                if (c == 'a' + i || c == 'A' + i) {
                    letterCount[i].first = c;
                    letterCount[i].second++;
                    if (letterCount[i].second > maxCount) {
                        maxCount = letterCount[i].second;
                    }
                    break;
                }
            }
        }
    }

    displayLetterCount(letterCount);
    return maxCount;
    
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    int mostOccurLetter = getMostOccurLetter(input);
    std::cout << "Most occurring letter count: " << mostOccurLetter << "\n";

    
    return 0;
}