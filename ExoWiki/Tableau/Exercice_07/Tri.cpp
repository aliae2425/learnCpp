#include "../lib/Tableau.h"

int main() {

    Tableau tableau;
    std::vector<int> table;

    // Initialisation du tableau
    tableau.setUpTableau(table, 10);
    tableau.printTable(table, "Tableau Initial");

    return 0;
}