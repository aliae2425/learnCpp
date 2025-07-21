#include <iostream>
#include <cmath>
#include <vector>

const std::vector<double> TEST = {1.5, 1, 2, 0.5, 3};

double f(double x, bool& ok) {
    double value = (x-1)*(x-2);
    if (value >= 0) {
        ok = true; // Indique que la valeur est positive
        return sqrt(value); // Retourne la racine carrée de la valeur
    }else {
        ok = false; // Indique que la valeur est négative
        return 0.0; // Retourne 0 en cas d'erreur
    }
}


int main() {
    double x;
    bool ok = true; // Variable pour indiquer si la valeur est valide

    std::cout << "test : ";
    for (const auto& val : TEST) {
    double result = f(val, ok);
        if (ok) {
            std::cout << "La racine de (" << val-1 << ") * (" << val-2 << ") est : " << result << std::endl;
        } else {
            std::cout << "Erreur" << std::endl;
        }
    }

    return 0;
}