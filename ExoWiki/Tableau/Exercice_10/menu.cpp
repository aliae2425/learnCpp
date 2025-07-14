#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
    #include <windows.h>
    #include <io.h>
    #include <fcntl.h>
#endif



const std::string VERT = "\033[32m";
const std::string RESET = "\033[0m";
const std::string ROUGE = "\033[31m";


void printMenu(){
    std::cout << "Appuyez sur Entrée pour continuer...";
    std::cin.ignore(10000, '\n');
    std::cin.get();

    for (int i = 0; i < 12; ++i) {
        std::cout << "\033[A"; // Remonter d'une ligne
        std::cout << "\033[K";
    }

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
    for (int i = 0; i < 10; ++i) {
        int nombre = rand() % 100; // Générer un nombre aléatoire entre 0 et 99
        table.push_back(nombre);
    }
}

void sortTable(std::vector<int> &table) {
    std::sort(table.begin(), table.end());
}

void printLastValue(const std::vector<int> &table) {
    if (!table.empty()) {
        std::cout << "Le dernier nombre ajouté est : " << table.back() << std::endl;
    } else {
        std::cout << "Le tableau est vide." << std::endl;
    }
}

void removeValue(std::vector<int> &table, int value) {
    auto it = std::remove(table.begin(), table.end(), value);
    if (it != table.end()) {
        table.erase(it, table.end());
        std::cout << "Valeur " << value << " supprimée du tableau." << std::endl;
    } else {
        std::cout << "Valeur " << value << " non trouvée dans le tableau." << std::endl;
    }
}

void addValue(std::vector<int> &table, int value) {
    table.push_back(value);
    std::cout << "Valeur " << value << " ajoutée au tableau." << std::endl;
}

int main() {

    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif

    srand(time(nullptr));

    std::vector<int> table;
    std::string choice;
    int value;
    bool continuer = true;

    while (continuer) {
        printMenu();
        std::cout << "Choisissez une option : ";
        std::cin >> choice;

        if (choice == "1" || choice == "add") {
            std::cout << "Entrez un nombre à ajouter : ";
            std::cin >> value;
            addValue(table, value);
        }else if (choice =="rand"){
            remplirTableau(table, 10);
            std::cout << "Tableau rempli avec des valeurs aléatoires." << std::endl;
        } else if (choice == "2" || choice == "remove") {
            std::cout << "Entrez un nombre à supprimer : ";
            std::cin >> value;
            removeValue(table, value);
        } else if (choice == "3" || choice == "print") {
            printTable(table);
            printTable(table, "Valeurs");
        } else if (choice == "4" || choice == "sort") {
            sortTable(table);
            std::cout << "Tableau trié." << std::endl;
        } else if (choice == "5" || choice == "last") {
            printLastValue(table);
        } else if (choice == "6" || choice == "q") {
            continuer = false;
        } else {
            std::cout << ROUGE << "Option invalide, veuillez réessayer." << RESET << std::endl;
        }
        std::cout << std::endl;

    }

    return 0;
}
