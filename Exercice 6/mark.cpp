#include <iostream>

bool passMark(int mark) {
    return mark >= 10;
}

int main() {
    int mark;
    std::cout << "Entrez votre note: ";
    std::cin >> mark;
    
    std::cout << "Votre note est " << (passMark(mark) ? "suffisante." : "insuffisante.") << std::endl;

    return 0;
}