#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

void printtable(std::vector<int> &table) {
    std::cout << "Tableau: ";
    for (size_t i = 0; i < table.size(); ++i) {
        std::cout << std::setw(3) << table[i];
        if (i < table.size() - 1) {
            std::cout << " | ";
        }
    }
    std::cout << std::endl;
}

int main(){
    bool continuer = true;
    std::vector<int> table;
    std::string input = "0";

    std::cout << "Entrez un nombre entier (ou 'q' pour quitter): ";

    while (continuer)
    {
        std::cin >> input;

        if (input == "q" || input == "Q") {
            continuer = false;
        } else {
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

        /* code */
    }

    std::cout << "Programme terminé." << std::endl;
    printtable(table); // Afficher le tableau final
    return 0;    
    
}