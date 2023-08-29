#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

std::vector<int> sort_vec(std::vector<int> v) {
    std::sort(v.begin(), v.end());
    return v;
}

int main() {
    map<char, vector<int>> datasets;

    char datasetIdentifier;
    int value;

    while (cin >> datasetIdentifier >> value) {
        datasets[datasetIdentifier].push_back(value);
    }

    for (const auto& entry : datasets) {
        for (int val : sort_vec(entry.second)) {
            cout << val << " ";
        }
    }

    cout << endl;

    return 0;
}
