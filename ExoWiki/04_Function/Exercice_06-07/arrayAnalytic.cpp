#include <iostream>
#include <vector>

const std::vector<std::tuple<std::vector<int>, int , bool, int>> testCases = {
    {{1, 2, 3, 4, 5}, 2, true, 5},
    {{10, 20, 30, 9}, 3, false, 1},
    {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 9, true, 9},
    {{0, -1, -2}, 2, false, 0},
    {{-10, -20, -30}, 3, false, 0},
    {{1, 2, 3, 4, 5, 6}, 3, true, 6}
};

bool findDecimal(const std::vector<int>& arr, int n) {
     for (int i = 0; i < n; ++i) {
        if (arr[i] < 10 && arr[i] > 0) {
            return true; // Found a decimal number
        }
     }
     return false;
}

int numberOfDecimal(const std::vector<int>& arr) {
    int count = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] < 10 && arr[i] > 0) {
            count++;
        }
    }
    return count;
}

int main(){
    int passedTests = 0;
    int i = 0;
    std::cout << "Running tests for exercise 06 function...\n";
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

    // Additional tests for exercise 07
    i = 0;
    passedTests = 0;
    std::cout << "\n----------------------------------------\n";
    std::cout << "Running tests for exercise 07 function...\n";

    for (const auto& test : testCases) {
        i++;
        if (numberOfDecimal(std::get<0>(test)) == std::get<3>(test)) {
            passedTests++;
            std::cout << " Test " << i << ": Passed\n";
        } else {
            std::cout << " Test " << i << ": Failed\n";
        }
    }
    std::cout << "All tests completed.\n";
    std::cout << "Passed tests: " << passedTests << "/" << testCases.size() << "\n";
    std::cout << "----------------------------------------\n";
    return 0;
}