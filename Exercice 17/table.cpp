#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>


std::vector<int> createTable(int size) {
    std::vector<int> table(size);
    for (int i = 0; i < size; ++i) {
        table[i] = rand() % 100; // Random numbers between 0 and 99
    }
    return table;
}

// void displayTable(const std::vector<int>& table) {
void displayTable(std::vector<int> &table,const std::string title = "Index") {
    std::cout << std::setw(10)<< title  << " |" << std::endl;
    for (size_t i = 0; i < table.size(); ++i) {
        if (title == "Index") {
            std::cout << std::setw(4) << i + 1 << " |";
        } else {
        std::cout << std::setw(4) << table[i] << " |";
        }
    }
    std::cout << std::endl;
}

int average(const std::vector<int>& table) {
    int sum = 0;
    for (int value : table) {
        sum += value;
    }
    return sum / table.size();
}

void sortTable(std::vector<int>& table) {
    for (int i = 0; i < table.size() - 1; ++i) {
        for (int j = 0; j < table.size() - i - 1; ++j) {
            if (table[j] > table[j + 1]) {
                std::swap(table[j], table[j + 1]);
            }
        }
    }
}

int main(){
    // Initialiser la seed pour les nombres aléatoires
    srand(time(nullptr));
    
    int tableSize;
    std::cout << "entrez la taille de la table: ";
    std::cin >> tableSize;
    if (tableSize <= 0) {
        std::cout << "Veuillez entrer un nombre entier positif." << std::endl;
        return 1; // Exit with an error code
    }


    std::vector<int> table = createTable(tableSize);
    displayTable(table);
    displayTable(table, "Valeurs");
    sortTable(table);
    displayTable(table, "triées");

    std::cout <<std::endl << "La moyenne de la table est: " << average(table) << std::endl;

    return 0;
}