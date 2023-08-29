#include <iostream>

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    int prev = 1;
    int curr = 1;
    for (int i = 2; i <= n; i++) {
        int temp = curr;
        curr = prev + curr;
        prev = temp;
    }
    return curr;
}

int main() {
    int num;

    while (std::cin >> num) {
        int fib = fibonacci(num);
        std::cout << fib << " ";
    }

    return 0;
}
