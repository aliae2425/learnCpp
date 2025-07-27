#include <iostream>
#include <vector>

const std::vector<std::tuple<std::vector<int>, int, bool, int>> testCases = {
    {{1, 2, 3, 4, 5}, 2, true, 0},
    {{10, 20, 30, 9}, 3, true, 0},
    {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 9, true, 0},
    {{0, -1, -2}, 2, false, -1},
    {{-10, -20, -30}, 3, false, -1},
    {{1, 2, 3, 4, 5, 6}, 3, true, 0}
};

bool findDecimal(const std::vector<int>& arr, int n, int &count) {
    count = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] <= 10 && arr[i] > 0) {
            count = i;
            return true; // Found a decimal number
        }
    }
    return false;
}

int main() {
    int index;
    int passedTests = 0;
    int i = 0;
    std::cout << "Running tests for exercice 08 function...\n";
    for(const auto& test : testCases) {
        ++i;
        index = 0;
        bool result = findDecimal(std::get<0>(test), std::get<1>(test), index);
        if (result == std::get<2>(test) && index == std::get<3>(test)) {
            std::cout << "Test " << i << ": Passed\n";
            ++passedTests;
        } else {
            std::cout << "Test " << i << ": Failed\n";
        }
    }
    std::cout << "All tests completed.\n";
    std::cout << "Passed tests: " << passedTests << "/" << testCases.size() << "\n";

    return 0;
}
