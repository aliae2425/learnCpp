#include <iostream>
#include <vector>

void printPascal(const int& N){
    std::vector<std::vector<int>> triangle(N);

    for (int i = 0; i < N; ++i) {
        triangle[i].resize(i + 1);
        triangle[i][0] = 1;
        triangle[i][i] = 1;

        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    for (const auto& row : triangle) {
        for (const auto& value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int N;
    std::cout << "Entrez le nombre de lignes du triangle de Pascal (entre 1 et 20): ";
    std::cin >> N;

    if (N < 0) {
        std::cout << "Le nombre de lignes doit être positif." << std::endl;
        return 1;
    }else if (N > 20) {
        std::cout << "Le nombre de lignes doit être inférieur ou égal à 20." << std::endl;
        return 1;
    }

    printPascal(N);
    return 0;
}