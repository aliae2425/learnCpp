#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

#ifdef _WIN32
    #include <windows.h>
    #include <io.h>
    #include <fcntl.h>
#endif


const std::string VERT = "\033[32m";
const std::string RESET = "\033[0m";
const std::string ROUGE = "\033[31m";


void printTable(std::vector<int> &table) {
    std::cout << std::setw(15) << "index: ";
    for (size_t i = 0; i < table.size(); ++i) {
        std::cout << std::setw(3) << i;
        if (i < table.size() - 1) {
            std::cout << " | ";
        }
    }
    std::cout << std::endl;
    std::cout << std::setw(15) << "Tableau: ";
    for (size_t i = 0; i < table.size(); ++i) {
        std::cout << std::setw(3) << table[i];
        if (i < table.size() - 1) {
            std::cout << " | ";
        }
    }
    std::cout << std::endl << std::endl;
}

void typeOfTable(std::vector<int> &table) {
    int type = 0; 
    for (int i = 0; i < table.size(); ++i) {
        if (table[i] > table[i-1] && type == 2) {
            type = 0; // Tableau quelconque
        } else if (table[i] < table[i-1] && type == 1) {
            type = 0; // Tableau quelconque
        } else if (table[i] > table[i-1]) {
            type = 1; // Tableau croissant
        } else if (table[i] < table[i-1]) {
            type = 2; // Tableau décroissant
        } else {
            type = 3; // Tableau constant
        }
    } 

    switch (type) {
        case 0:
            std::cout << "Le tableau n'est ni croissant ni décroissant." << std::endl;
            break;
        case 1:
            std::cout << "Le tableau est croissant." << std::endl;
            break;
        case 2:
            std::cout << "Le tableau est décroissant." << std::endl;
            break;
        case 3:
            std::cout << "Le tableau est constant." << std::endl;
            break;
        default:
            std::cout << "Type de tableau inconnu." << std::endl;
    }

}


// Test graphique 
void afficherGraphiqueBarres(const std::vector<int>& donnees, int hauteurMax = 10) {
    if (donnees.empty()) return;
    
    int maxVal = *std::max_element(donnees.begin(), donnees.end());
    if (maxVal == 0) maxVal = 1;
    
    std::cout << "\nGraphique en barres:" << std::endl;
    
    // Afficher de haut en bas
    for (int ligne = hauteurMax; ligne > 0; --ligne) {
        std::cout << std::setw(3) << ligne << " |";
        
        for (size_t i = 0; i < donnees.size(); ++i) {
            int hauteurBarre = (donnees[i] * hauteurMax) / maxVal;
            if (hauteurBarre >= ligne) {
                std::cout << " ██";
            } else {
                std::cout << "   ";
            }
        }
        std::cout << std::endl;
    }
    
    // Ligne de base
    std::cout << "    +";
    for (size_t i = 0; i < donnees.size(); ++i) {
        std::cout << "---";
    }
    std::cout << std::endl;
    
    // Index
    std::cout << "     ";
    for (size_t i = 0; i < donnees.size(); ++i) {
        std::cout << std::setw(3) << i;
    }
    std::cout << std::endl;
    
    // Valeurs
    std::cout << "     ";
    for (size_t i = 0; i < donnees.size(); ++i) {
        std::cout << std::setw(3) << donnees[i];
    }
    std::cout << std::endl;
}

int main(){

    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif

    srand(time(nullptr));

    bool continuer = true;
    int value = 0;
    int index = 0;

    std::vector<int> table;
    std::string input = "0";

    std::cout << "Entrez un nombre entier ('q' pour quitter, 'rand' pour remplir le tableau): ";

    while (continuer)
    {
        std::cin >> input;

        if (input == "q" || input == "Q") {
            continuer = false;
        }
        else if (input == "rand"){
            for (int i = 0; i < 10; ++i) {
                int nombre = rand() % 10; // Générer un nombre aléatoire entre 0 et 99
                table.push_back(nombre);
            }
            break; // Sortir de la boucle pour éviter de demander à nouveau une entrée
        }
         else {
            try {
                int nombre = std::stoi(input);
                table.push_back(nombre);
            } catch (const std::invalid_argument &e) {
                std::cout << "Entrée invalide, veuillez entrer un nombre entier." << std::endl;
            } catch (const std::out_of_range &e) {
                std::cout << "Nombre hors de portée." << std::endl;
            }
        }

        if (table.size() >= 10) {
            std::cout << "Le tableau a atteint sa taille maximale de 10 éléments." << std::endl;
            continuer = false; // Arrêter la boucle si le tableau est plein
        }
    }

    std::cout << "Tableau initial: " << std::endl;
    printTable(table);
    std::cout << std::endl << std::endl;
    typeOfTable(table);    

    std::cout << "Affichage graphique:" << std::endl;
    afficherGraphiqueBarres(table);

    std::cout << "✅ Programme terminé." << std::endl;
    return 0;    
}