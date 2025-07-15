#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

#ifdef _WIN32
    #include <windows.h>
    #include <io.h>
    #include <fcntl.h>
#endif


const std::string VERT = "\033[32m";
const std::string RESET = "\033[0m";
const std::string ROUGE = "\033[31m";

void printtable(std::vector<int> &table, int value = 0) {
    std::cout << "Tableau: ";
    for (size_t i = 0; i < table.size(); ++i) {
        std::cout << (table[i]== value? VERT: RESET) << std::setw(3) << table[i] << RESET;
        if (i < table.size() - 1) {
            std::cout << " | ";
        }
    }
    std::cout << std::endl;
}

int countValue(std::vector<int> &table, int value) {
    int count = 0;
    for (int num : table) {
        if (num == value) {
            count++;
        }
    }
    return count;
}

int main(){

    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif

    bool continuer = true;
    int value = 0;

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

    std::cout << "quel valeur voulez-vous chercher dans le tableau? ";
    std::cin >> value;

    std::cout << "✅ Programme terminé." << std::endl;
    std::cout << "Nombre de valeurs égales à " << value << ": " << countValue(table, value) << std::endl;
    std::cout << "Tableau avec la valeur recherchée en vert: " << std::endl;
    printtable(table, value); // Afficher le tableau final

    return 0;    
    
}