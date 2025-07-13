#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

const std::string VERT = "\033[32m";
const std::string RESET = "\033[0m";
const std::string ROUGE = "\033[31m";


void printMenu(){

    std::cout << "Bienvenue dans le menu principal." << std::endl;
    std::cout << "1 ou add : Ajouter un nombre au tableau." << std::endl;
    std::cout << "2 ou remove : Supprimer un nombre du tableau." << std::endl;
    std::cout << "3 ou print : Afficher le tableau." << std::endl;
    std::cout << "4 ou sort : Trier le tableau." << std::endl;
    std::cout << "5 ou last : Afficher le dernier nombre ajouté." << std::endl;
    std::cout << "6 ou q : Quitter le programme." << std::endl;
}


void printTable(std::vector<int> &table, const std::string &title = "Index"){

    std::cout << std::setw(20) << title << " : ";
    if (title == "Index") {
        for (size_t i = 0; i < table.size(); ++i) {
        std::cout << std::setw(3) << i;
        if (i < table.size() - 1) {
            std::cout << " | ";
        }
    }
    } else {
        for (size_t i = 0; i < table.size(); ++i) {
            std::cout << std::setw(3) << table[i];
            if (i < table.size() - 1) {
                std::cout << " | ";
            }
        }
    }
    std::cout << std::endl;
}

void remplirTableau(std::vector<int> &table, int size = 10) {
 
    bool continuer = true;
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

        if (table.size() >= 10) {
            std::cout << "Le tableau a atteint sa taille maximale de 10 éléments." << std::endl;
            continuer = false; // Arrêter la boucle si le tableau est plein
        }
    }

}

void sortTable(std::vector<int> &table) {
    std::sort(table.begin(), table.end());
}

void handleMenuOption(const std::string &option, std::vector<int> &table) {
    
    switch (option)
    {
        case  "1":
        case "add":
            {
                int value;
                std::cout << "Entrez un nombre à ajouter au tableau: ";
                std::cin >> value;
                table.push_back(value);
                std::cout << "Nombre ajouté avec succès." << std::endl;
            }
            /* code */
            break;
        
        default:
            break;
    }
}
