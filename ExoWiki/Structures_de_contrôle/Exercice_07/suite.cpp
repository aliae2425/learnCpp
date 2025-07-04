#include <iostream>

// Fonction pour calculer u(n) de manière itérative
int calculerU(int n) {
    if (n == 0) {
        return 3;  // u(0) = 3
    }
    
    int u = 3;  // u(0) = 3
    
    // Calcul itératif : u(n+1) = 3*u(n) + 4
    for (int i = 1; i <= n; ++i) {
        u = 3 * u + 4;
    }
    
    return u;
}

// Fonction pour afficher la suite jusqu'à N
void afficherSuite(int n) {
    std::cout << "\nSuite u(n) pour n de 0 à " << n << ":" << std::endl;
    int u = 3;  // u(0) = 3
    std::cout << "u(0) = " << u << std::endl;
    
    for (int i = 1; i <= n; ++i) {
        u = 3 * u + 4;
        std::cout << "u(" << i << ") = " << u << std::endl;
    }
}

int main() {
    int n;
    
    std::cout << "=== Calcul de la suite u(n) ===" << std::endl;
    std::cout << "u(0) = 3" << std::endl;
    std::cout << "u(n+1) = 3*u(n) + 4" << std::endl;
    std::cout << "===============================" << std::endl;
    
    std::cout << "\nEntrez un entier N: ";
    std::cin >> n;
    
    // Validation de l'entrée
    if (n < 0) {
        std::cout << "Erreur: N doit être un entier positif ou nul." << std::endl;
        return 1;
    }
    
    // Calcul et affichage du résultat
    int resultat = calculerU(n);
    std::cout << "\nRésultat: u(" << n << ") = " << resultat << std::endl;
    
    // Demander si l'utilisateur veut voir toute la suite
    char choix;
    std::cout << "\nVoulez-vous voir toute la suite de u(0) à u(" << n << ")? (o/n): ";
    std::cin >> choix;
    
    if (choix == 'o' || choix == 'O') {
        afficherSuite(n);
    }
    
    return 0;
}
