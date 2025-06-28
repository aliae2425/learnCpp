#include <iostream>


const int T1 = 10, T2 = 20; 
const double tarifT1 = 0.25, tarifT2 = 0.20, TarifT3 = 0.10;

double tranche (int count) {
    double total = 0.0;
    if (count <= T1) {
        total += count * tarifT1;
    } else if (count <= T2) {
        total += T1 * tarifT1 + (count - T1) * tarifT2;
    } else {
        total += T1 * tarifT1 + (T2) * tarifT2 + (count - (T2+T1)) * TarifT3;
    }
    return total;
}


int main(){
    int count = 0;
    std::cout << "Combien voulez vous faire de photocopies ? ";
    std::cin >> count;

    std::cout << "Le montant total est: " << tranche(count) << " euros." << std::endl;
    std::cout << "Merci de votre confiance." << std::endl;

    return 0;
}