#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 0) {
        return 0;
    }

    vector<int> numbers(n);
    int largestIndex = 0;

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
        if (numbers[i] > numbers[largestIndex]) {
            largestIndex = i;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i == largestIndex) {
            cout << "*" << numbers[i] << "*";
        } else {
            cout << numbers[i];
        }

        if (i < n - 1) {
            cout << " ";
        }
    }

    cout << endl;

    return 0;
}
