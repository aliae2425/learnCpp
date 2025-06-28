#include <iostream>
#include <vector>

const int SIZE = 5; // Define a maximum size for the vector

int average(const std::vector<int>& table) {
    if (table.empty()) return 0; // Handle empty vector case
    int sum = 0;
    for (int value : table) {
        sum += value;
    }
    return sum / table.size();
}

int main() {

    std::vector<int> table(SIZE);
    std::cout << "Entrez les valeurs de la table:" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        std::cin >> table[i];
    }

    std::cout << "La moyenne de la table est: " << average(table) << std::endl;

    return 0;
}
