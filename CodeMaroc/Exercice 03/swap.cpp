#include <iostream>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;
    std::cout << "Entrez deux nombres: ";
    std::cin >> x >> y;
    
    std::cout << "Avant l'échange: x = " << x << ", y = " << y << std::endl;
    
    swap(x, y);
    
    std::cout << "Après l'échange: x = " << x << ", y = " << y << std::endl;
    
    return 0;
}