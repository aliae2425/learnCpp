#include <iostream>
#include <iomanip>
#include <string>

void drawTree(int height){
    for (int i = height; i >= 0; --i) {
        std::string text(i, '*');
        std::cout << std::setw(height) << text << std::endl;
    }
}

int main(){
    int height;
    std::cout << "Entrez la hauteur du sapin: ";
    std::cin >> height;

    if (height <= 0) {
        std::cout << "Veuillez entrer une hauteur positive." << std::endl;
        return 1; // Exit with an error code
    }

    drawTree(height);
    
    return 0;
}