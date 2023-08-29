#include <algorithm>
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

    int scalarProduct = 0;

    if (datasets.count('a') && datasets.count('b')) {
        size_t size = max(datasets['a'].size(), datasets['b'].size());

        for (size_t i = 0; i < size; ++i) {
            int aVal = (i < datasets['a'].size()) ? datasets['a'][i] : 0;
            int bVal = (i < datasets['b'].size()) ? datasets['b'][i] : 0;
            scalarProduct += aVal * bVal;
        }
    }

    cout << scalarProduct << endl;

    return 0;
}
