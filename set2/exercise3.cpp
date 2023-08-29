#include <cmath>
#include <iostream>

double pi(int n) {
    double sum = 0.0;

    for (int i = 0; i < n; ++i) {
        double term = (i % 2 == 0) ? 1.0 : -1.0;
        term /= 2 * i + 1;
        sum += term;
    }

    return 4.0 * sum;
}

int main() {
    int n;

    std::cin >> n;
    double approximation = pi(n);
    std::cout << approximation << std::endl;

    return 0;
}
