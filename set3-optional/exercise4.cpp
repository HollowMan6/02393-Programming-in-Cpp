#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int numIntervals, dataSize;
    cin >> numIntervals >> dataSize;

    vector<int> data(dataSize);
    for (int i = 0; i < dataSize; ++i) {
        cin >> data[i];
    }

    int maxValue = *max_element(data.begin(), data.end());
    int intervalSize = ceil(static_cast<double>(maxValue) / numIntervals);

    bool divisible = (maxValue % numIntervals == 0);

    vector<int> intervalCounts(numIntervals);

    for (int num : data) {
        int intervalIndex = num / intervalSize;
        intervalCounts[intervalIndex]++;
    }

    if (divisible) {
        intervalCounts[numIntervals - 1]++;
    }

    for (int i = 0; i < numIntervals; ++i) {
        int lowerBound = i * intervalSize;
        int upperBound = (i + 1) * intervalSize - 1;
        cout << lowerBound << ": " << intervalCounts[i] << endl;
    }

    return 0;
}
