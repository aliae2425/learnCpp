#include <iostream>
#include <vector>

double average(const std::vector<int>& numbers) {
    if (numbers.empty()) return 0.0;

    double sum = 0.0;
    for (int num : numbers) {
        sum += num;
    }
    return sum / numbers.size();
}

int main() {
    int n;
    std::cout << "Combien de nombres voulez-vous entrer ? ";
    std::cin >> n;

    std::vector<int> numbers(n);
    std::cout << "Entrez les " << n << " nombres : ";
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    double avg = average(numbers);
    std::cout << "La moyenne est : " << avg << std::endl;

    return 0;
}