#include "Tableau.h"
#include <iostream>
#include <iomanip>
#include <vector>


void Tableau::printTable(const std::vector<int> &table, const std::string &title, int highlightIndex) {

    // header    
    std::cout << std::setw(15) << "index: ";
    for (size_t i = 0; i < table.size(); ++i) {
        std::cout << std::setw(3) << i;
        if (i < table.size() - 1) {
            std::cout << " | ";
        }
    }

    std::cout << std::endl;
    
    // content
    std::cout << std::setw(15) << title << " : ";
    for (size_t i = 0; i < table.size(); ++i) {
        std::cout << (i == highlightIndex? VERT : RESET ) << std::setw(3) << table[i] << RESET;
        if (i < table.size() - 1) {
            std::cout << " | ";
        }
    }
    std::cout << std::endl << std::endl;
}


int Tableau::setUpTableau(std::vector<int> &table, const  int size) {
    std::string input = "0";
    bool continuer = true;
    std::cout << "Entrez un nombre entier ('q' pour quitter, 'rand' pour remplir le tableau): ";

    while (continuer)
    {
        std::cin >> input;

        if (input == "q" || input == "Q") {
            continuer = false;
        }
        else if (input == "rand"){
            for (int i = 0; i < size; ++i) {
                int nombre = rand() % 100; // Générer un nombre aléatoire entre 0 et 99
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

        if (table.size() >= size) {
            std::cout << "Le tableau a atteint sa taille maximale de "<< size << " éléments." << std::endl;
            continuer = false; // Arrêter la boucle si le tableau est plein
        }
    }

    return 0;
}