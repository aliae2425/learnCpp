#ifndef TABLEAU_H
#define TABLEAU_H

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
const std::string JAUNE = "\033[33m";
const std::string BLEU = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string BLANC = "\033[37m";

class Tableau {
    public:
        void printTable(
            const std::vector<int> &table,
            const std::string &title = "Tableau",
            const int highlightIndex = -1
            );
        int setUpTableau(std::vector<int> &table, const int size = 10);

};

#endif // TABLEAU_H