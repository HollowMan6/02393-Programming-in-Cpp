#include <iostream>
#include <vector>

int main() {
    const int maxValue = 1000;
    std::vector<int> count(maxValue + 1, 0);

    while (true) {
        int value;
        std::cin >> value;

        if (value == 0) {
            break;
        }

        if (value >= 1 && value <= maxValue) {
            std::cout << count[value] << std::endl;
            count[value]++;
        }
    }

    return 0;
}
