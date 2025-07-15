#include <iostream>


bool valideEntier(char chaine[], int &refNombreEntier) {
    
    bool valide = true;
    refNombreEntier = 0;
    
    valide = !(chaine[0] < '1' || chaine[0] > '9');

    int compteur = 0;
    while (valide && chaine[compteur]!='\0') {
        if (chaine[compteur] >= '0' && chaine[compteur] <= '9') {
            refNombreEntier = 10 * refNombreEntier + (chaine[compteur] - '0');
            compteur++;
        } else {
            valide = false;
        }
    }
    return valide;
}

int main() {

    int nombreEntier;
    char chaine[20];

    do {
        std::cout << "Tapez une chaîne de caractères : "; 
        std::cin >> chaine;
    } while (!valideEntier(chaine, nombreEntier));

    std::cout << "L'entier vaut : " << nombreEntier << std::endl;
    return 0;
}