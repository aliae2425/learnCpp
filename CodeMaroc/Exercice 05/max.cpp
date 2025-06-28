#include <iostream>
#include <vector>

int max (std::vector<int> a) {
    int maxValue = a[0];
    for(int i =0; i < a.size(); i++){
        if(a[i] > maxValue){
            maxValue = a[i];
        }
    }
    return maxValue;
}

int n;
int main() {
    std::cout << "combien d'element sont a comparer ?: " << std::endl;
    std::cin >> n ;

    std::vector<int> numbers(n);
    std::cout << "Entrez les " << n << " nombres: " << std::endl;
    for(int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }

    int maxValue = max(numbers);
    std::cout << "Le maximum est: " << maxValue << std::endl;

    return 0;
}