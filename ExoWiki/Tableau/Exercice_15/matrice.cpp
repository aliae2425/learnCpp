#include <iostream>
#include <vector>
#include <iomanip>

#ifdef _WIN32
    #include <windows.h>
    #include <io.h>
    #include <fcntl.h>
#endif

const std::string VERT = "\033[32m";
const std::string RESET = "\033[0m";

int average(const std::vector<int>& row) {
    if (row.empty()) return 0;
    int sum = 0;
    for (const auto& value : row) {
        sum += value;
    }
    return sum / static_cast<int>(row.size());
}

void printMatrice(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        std::cout << "| ";
        for (const auto& value : row) {
            std::cout << std::setw(5) << value << " | ";
        }
        std::cout << VERT << "[" << average(row)<< "]" << RESET << " ";
        std::cout << std::endl;
    }
}

void remplirMatrice(std::vector<std::vector<int>>& matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        std::vector<int> row;
        for (int j = 0; j < cols; ++j) {
            row.push_back(rand() % 100); // Remplir avec des nombres aléatoires entre 0 et 99
        }
        matrix.push_back(row);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Initialiser le générateur de nombres aléatoires

    int rows, cols;
    std::cout << "Entrez le nombre de lignes de la matrice: ";
    std::cin >> rows;
    std::cout << "Entrez le nombre de colonnes de la matrice: ";
    std::cin >> cols;

    std::vector<std::vector<int>> matrix;
    remplirMatrice(matrix, rows, cols);

    std::cout << "Matrice remplie:" << std::endl;
    printMatrice(matrix);

    return 0;
}