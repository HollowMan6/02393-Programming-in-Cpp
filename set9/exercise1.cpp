#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;
    int num;

    // Read integers from standard input
    while (std::cin >> num) {
        numbers.push_back(num);
    }

    // Output the reversed sequence
    for (int i = numbers.size() - 1; i >= 0; i--) {
        std::cout << numbers[i] << " ";
    }

    return 0;
}
