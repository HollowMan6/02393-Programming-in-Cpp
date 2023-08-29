#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    map<char, vector<int>> datasets;

    char datasetIdentifier;
    int value;

    while (cin >> datasetIdentifier >> value) {
        datasets[datasetIdentifier].push_back(value);
    }

    size_t maxCount = 0;
    for (const auto& entry : datasets) {
        maxCount = max(maxCount, entry.second.size());
    }

    for (size_t i = 0; i < maxCount; ++i) {
        for (const auto& entry : datasets) {
            if (i < entry.second.size()) {
                cout << entry.second[i] << " ";
            }
        }
    }

    cout << endl;

    return 0;
}
