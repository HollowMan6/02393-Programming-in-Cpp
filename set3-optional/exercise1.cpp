#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 1) {
        cout << "SORTED" << endl;
        return 0;
    }

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    bool isSorted = true;
    for (int i = 1; i < n; ++i) {
        if (numbers[i] < numbers[i - 1]) {
            isSorted = false;
            break;
        }
    }

    if (isSorted) {
        cout << "SORTED" << endl;
    } else {
        cout << "UNSORTED" << endl;
    }

    return 0;
}
