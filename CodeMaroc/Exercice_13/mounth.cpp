#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> months = {
        "Janvier", "Février", "Mars", "Avril", "Mai", "Juin",
        "Juillet", "Août", "Septembre", "Octobre", "Novembre", "Décembre"
    };

    int monthNumber;
    std::cout << "Entrez un numéro de mois (1-12): ";
    std::cin >> monthNumber;

    if (monthNumber < 1 || monthNumber > 12) {
        std::cout << "Numéro de mois invalide, veuillez entrer un nombre entre 1 et 12." << std::endl;
    } else {
        std::cout << "Le mois est: " << months[monthNumber - 1] << std::endl;
    }

    return 0;
}