#include <iostream>

int tva = 20;
int taux = 15;

int reduction(int total){
    return total - (total * taux / 100);
}

int ttc(int total) {
    return total + (total * tva / 100);
}

int main() {
    int total;
    std::cout << "Entrez le montant total HT: ";
    std::cin >> total;

    int totalReduction = reduction(total);
    int totalTTC = ttc(totalReduction);

    std::cout << "Le montant après réduction est: " << totalReduction << std::endl;
    std::cout << "Le montant TTC est: " << totalTTC << std::endl;

    return 0;
}