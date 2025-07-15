#include <iostream>
#include <iomanip> // For std::setw

const int TVA_RATE = 20; // Taux de TVA en pourcentage


double TVA( int montant) {
    return montant * (TVA_RATE/100); // 20% de TVA
}

int main() {
    double prixKg, quantite;
    std::cout << "Entrez le prix par kilogramme: ";
    std::cin >> prixKg;
    std::cout << "Entrez la quantité en kilogrammes: ";
    std::cin >> quantite;

    if (prixKg < 0 || quantite < 0) {
        std::cout << "Veuillez entrer des valeurs positives pour le prix et la quantité." << std::endl;
        return 1; // Exit with an error code
    }

    double montantHT = prixKg * quantite; // Montant hors taxes
    double montantTVA = TVA(montantHT); // Montant de la TVA
    double montantTTC = montantHT + montantTVA; // Montant toutes taxes comprises

    std::cout << "Montant hors taxes: " << std::setw(25) << montantHT << " MAD" << std::endl;
    std::cout << "Montant de la TVA: " << std::setw(25) << montantTVA << " MAD" << std::endl;
    std::cout << "Montant toutes taxes comprises: "  << std::setw(25) << montantTTC << " MAD" << std::endl;

    return 0;
}