#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    // Find the index of the tallest (first from left)
    int maxHeight = heights[0], maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (heights[i] > maxHeight) {
            maxHeight = heights[i];
            maxIdx = i;
        }
    }

    // Find the index of the shortest (last from right)
    int minHeight = heights[0], minIdx = 0;
    for (int i = 1; i < n; i++) {
        if (heights[i] <= minHeight) {
            minHeight = heights[i];
            minIdx = i;
        }
    }

    int moves = maxIdx + (n - 1 - minIdx);
    if (maxIdx > minIdx) {
        moves--; // because they cross over when swapping
    }

    cout << moves << endl;
    return 0;
}
