#include <iostream>

int surface(int length, int width) {
    return (length * width);
}

int perimeter(int length, int width) {
    return 2 * (length + width);
}

int main() {
    int length, width;
    
    std::cout << "Entrez la longueur: ";
    std::cin >> length;
    
    std::cout << "Entrez la largeur: ";
    std::cin >> width;

    if (length <= 0 || width <= 0) {
        std::cout << "Veuillez entrer des valeurs positives pour la longueur et la largeur." << std::endl;
        return 1; // Exit with an error code
    }

    int surf = surface(length, width);
    int peri = perimeter(length, width);

    std::cout << "La surface du rectangle est: " << surf << std::endl;
    std::cout << "Le périmètre du rectangle est: " << peri << std::endl;

    return 0;
}