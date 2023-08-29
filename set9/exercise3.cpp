#include <iostream>
#include <vector>

bool isPalindrome(const std::vector<int>& numbers) {
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right) {
        if (numbers[left] != numbers[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    std::vector<int> numbers;
    int num;

    while (std::cin >> num) {
        numbers.push_back(num);
    }

    if (isPalindrome(numbers)) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    return 0;
}
