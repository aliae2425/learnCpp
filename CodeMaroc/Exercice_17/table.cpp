#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

// createTable function generates a vector of random integers
std::vector<int> createTable(int size) {
    std::vector<int> table(size);
    for (int i = 0; i < size; ++i) {
        table[i] = rand() % 20; // Random numbers between 0 and 99
    }
    return table;
}

// displayTable function prints the contents of the vector in a formatted way
void displayTable(std::vector<int> &table,const std::string title = "Index") {
    std::cout << std::setw(10)<< title  << " |";
    for (size_t i = 0; i < table.size(); ++i) {
        if (title == "Index") {
            std::cout << std::setw(4) << i + 1 << " |";
        } else {
            std::cout << std::setw(4) << table[i] << " |";
        }
    }
    std::cout << std::endl;
}

// average function calculates the average of the integers in the vector
int average(const std::vector<int>& table) {
    int sum = 0;
    for (int value : table) {
        sum += value;
    }
    return sum / table.size();
}

// sortTable function sorts the vector using bubble sort algorithm
void sortTable(std::vector<int>& table) {
    for (int i = 0; i < table.size() - 1; ++i) {
        for (int j = 0; j < table.size() - i - 1; ++j) {
            if (table[j] > table[j + 1]) {
                std::swap(table[j], table[j + 1]);
            }
        }
    }
}

template<typename T>
void dumpMatrice(const std::vector<std::vector<T>>& matrice, const std::string& nom = "matrice") {
    if (matrice.empty()) return;

    std::cout << std::setw(10) << nom << " |";
    for (size_t i = 0; i < matrice.size(); ++i) {
        std::cout << std::setw(4) << matrice[i][0] << " |";
    }
    std::cout << std::endl;

    std::cout << std::setw(10) << "Occurence" << " |";
    for (size_t i = 0; i < matrice.size(); ++i) {
        std::cout << std::setw(4) << matrice[i][1] << " |";
    }
    std::cout << std::endl;
}

// fonction qui affiche le nombre d'occurrences de chaque valeur dans la table
void countOccurrences(const std::vector<int>& table) {
    std::vector<std::vector<int>> TableDoccurence; 
    for (int i =0; i < table.size(); i++) {
        bool found = false;
        for (int j = 0; j < TableDoccurence.size(); j++) {
            if (TableDoccurence[j][0] == table[i]) {
                TableDoccurence[j][1]++;
                found = true;
                break;
            }
        }
        if (!found) {
            TableDoccurence.push_back({table[i], 1});
        }
    }

    dumpMatrice(TableDoccurence, "Valeurs");

}

void countOddAndEven(const std::vector<int>& table) {
    int oddCount = 0;
    int evenCount = 0;

    for (int value : table) {
        if (value % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    std::cout << "Nombre de valeurs paires: " << evenCount << std::endl;
    std::cout << "Nombre de valeurs impaires: " << oddCount << std::endl;
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
    displayTable(table, "triees");

    std::cout <<std::endl << "La moyenne de la table est: " << average(table) << std::endl;
    countOccurrences(table);
    std::cout << std::endl;
    countOddAndEven(table);

    return 0;
}