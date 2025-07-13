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

void triTable(std::vector<int> &table) {
    std::sort(table.begin(), table.end());
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

    std::cout << "Tableau initial: " << std::endl;
    printTable(table,"Index");
    printTable(table,"Valeurs");
    std::cout << "Tri du tableau..." << std::endl;
    triTable(table);
    printTable(table,"Tableau trié");

    std::cout << "✅ Programme terminé." << std::endl;
    return 0;    
}