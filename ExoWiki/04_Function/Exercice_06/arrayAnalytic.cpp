#include <iostream>
#include <vector>

const std::vector<std::tuple<std::vector<int>, int , bool>> testCases = {
    {{1, 2, 3, 4, 5}, 2, true},
    {{10, 20, 30, 9}, 3, false},
    {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 9, true},
    {{0, -1, -2}, 2, false},
    {{-10, -20, -30}, 3, false},
    {{1, 2, 3, 4, 5, 6}, 3, true}
};

bool findDecimal(const std::vector<int>& arr, int n) {
     for (int i = 0; i < n; ++i) {
        if (arr[i] < 10 && arr[i] > 0) {
            return true; // Found a decimal number
        }
     }
     return false;
}

int main(){
    int passedTests = 0;
    int i = 0;
    std::cout << "Running tests for findDecimal function...\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Test cases:\n";

    for (const auto& test : testCases){
        i++;
        if (findDecimal(std::get<0>(test), std::get<1>(test)) == std::get<2>(test)) {
            passedTests++;
            std::cout << "Test " << i << ": Passed\n";
        } else {
            std::cout << "Test " << i << ": Failed\n";
        }
        
    }

    std::cout << "All tests completed.\n";
    std::cout << "Passed tests: " << passedTests << "/" << testCases.size() << "\n";

    return 0;
}