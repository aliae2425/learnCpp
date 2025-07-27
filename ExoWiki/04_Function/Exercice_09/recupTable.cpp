#include <iostream>
#include <vector>
#include <tuple>



int numberOfDecimal(const std::vector<int>& arr, std::vector<int>& saveTable) {
    int count = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] < 10 && arr[i] > 0) {
            count++;
            saveTable.push_back(arr[i]);
        }
    }
    return count;
}



int main() {
    std::vector<int> arr = {15, 5, 53, 4, 21, 46, 7, 28, 49};
    std::vector<int> saveTable;
    
    int count = numberOfDecimal(arr, saveTable);
    
    std::cout << "Number of decimal numbers: " << count << std::endl;
    std::cout << "Decimal numbers: ";
    for (const auto& num : saveTable) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}



