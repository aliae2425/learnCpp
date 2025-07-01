#include <iostream>

const int u0 = 1;
const int u1 = 1;


// Fonction pour calculer u(n) avec la formule u(n+1) = u(n) + n(n-1)
// Il faut spécifier u(0) comme valeur initiale
int calculerSuite(int n, int u0 = 0) {
    if (n == 0) {
        return u0;  // Valeur initiale u(0)
    }
    
    int u = u0;  // u(0)
    
    // Calcul itératif : u(n+1) = u(n) + n(n-1)
    for (int i = 0; i < n; ++i) {
        u = u + i * (i - 1);  // u(i+1) = u(i) + i(i-1)
    }
    
    return u;
}

// Fonction récursive alternative
int calculerSuiteRecursif(int n, int u0 = 0) {
    if (n == 0) {
        return u0;  // Cas de base : u(0) = u0
    }
    // u(n) = u(n-1) + (n-1)(n-2)
    return calculerSuiteRecursif(n - 1, u0) + (n - 1) * (n - 2);
}

// Fonction pour afficher la suite jusqu'à N
void afficherSuiteComplete(int n, int u0 = 0) {
    std::cout << "\nSuite u(n) avec u(n+1) = u(n) + n(n-1):" << std::endl;
    std::cout << "u(0) = " << u0 << std::endl;
    
    int u = u0;
    for (int i = 0; i < n; ++i) {
        u = u + i * (i - 1);
        std::cout << "u(" << (i + 1) << ") = u(" << i << ") + " << i << "*(" << i << "-1) = " 
                  << "u(" << i << ") + " << (i * (i - 1)) << " = " << u << std::endl;
    }
}

int main() {
    int nValeur;
    std::cout << "Entrez un entier N: ";
    std::cin >> nValeur;

    if (nValeur < 2) {
        std::cout << "Erreur: N doit être un entier positif ou nul." << std::endl;
        return 1; // Exit with an error code
    }

    std::cout << "Valeur de u(" << nValeur << ") = " << calculerSuiteRecursif(nValeur) << std::endl;

    return 0;
}