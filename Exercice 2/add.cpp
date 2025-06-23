#include <iostream>

int add(int a, int b) {
    return a + b;
}

int main(){
    int a, b;
    std::cout <<"entrez deux nombres: ";
    std::cin >> a >> b;
    std::cout << "La somme de " << a << " et " << b << " est: " << add(a, b) << std::endl;
    return 0;
}