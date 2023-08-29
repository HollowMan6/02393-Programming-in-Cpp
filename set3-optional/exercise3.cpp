#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 1) {
        return 1;
    }

    vector<double> u(n);
    vector<double> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> u[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    double dotProduct = 0.0;
    for (int i = 0; i < n; ++i) {
        dotProduct += u[i] * v[i];
    }

    cout << dotProduct << endl;

    return 0;
}
