#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void permute(std::vector<T>& elements, int start, std::vector<std::vector<T>>& permutations) {
    if (start == elements.size() - 1) {
        permutations.push_back(elements);
        return;
    }

    for (int i = start; i < elements.size(); ++i) {
        std::swap(elements[start], elements[i]);
        permute(elements, start + 1, permutations);
        std::swap(elements[start], elements[i]); // Backtrack
    }
}

template<typename T>
std::vector<std::vector<T>> getPermutations(const std::vector<T>& elements) {
    std::vector<std::vector<T>> permutations;
    std::vector<T> copy = elements;
    permute(copy, 0, permutations);
    return permutations;
}

int main() {
    std::vector<int> elements = {1, 2, 3};
    std::vector<std::vector<int>> permutations = getPermutations(elements);

    for (const auto& perm : permutations) {
        for (const auto& num : perm) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
