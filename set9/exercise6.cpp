#include <iostream>
#include <vector>

template<typename T>
std::vector<std::vector<T>> powerset(const std::vector<T>& inputSet) {
    std::vector<std::vector<T>> result;
    int n = inputSet.size();
    int subsets = 1 << n;

    for (int i = 0; i < subsets; ++i) {
        std::vector<T> subset;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                subset.push_back(inputSet[j]);
            }
        }
        result.push_back(subset);
    }

    return result;
}

int main() {
    std::vector<int> inputSet = {1, 2, 3};
    std::vector<std::vector<int>> powerSet = powerset(inputSet);

    for (const auto& subset : powerSet) {
        for (const auto& element : subset) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
