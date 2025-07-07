/*
 * Author: Shreyash (shadcy)
 * Created: 2025-07-06
 * Template: Competitive Programming
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

void computeSolution() {
    int arraySize;
    cin >> arraySize;
    
    vll elements(arraySize + 2), prefixMin(arraySize + 2);
    vll suffixSum(arraySize + 3), diffArray(arraySize + 2);

    for (int i = 1; i <= arraySize; ++i) 
        cin >> elements[i];

    // Compute prefix minimum array
    prefixMin[1] = elements[1];
    for (int i = 2; i <= arraySize; ++i) 
        prefixMin[i] = min(prefixMin[i - 1], elements[i]);

    // Calculate total sum of prefix minimums
    ll totalSum = accumulate(prefixMin.begin() + 1, prefixMin.begin() + arraySize + 1, 0LL);

    // Compute suffix sums
    suffixSum[arraySize + 1] = 0;
    for (int i = arraySize; i >= 1; --i) 
        suffixSum[i] = prefixMin[i] + suffixSum[i + 1];

    // Find first position where prefix minimum stops decreasing
    int plateauPos = arraySize + 1;
    for (int i = 2; i < arraySize; ++i) {
        if (prefixMin[i] == prefixMin[i - 1]) {
            plateauPos = i;
            break;
        }
    }

    // Compute difference array
    for (int i = 2; i <= arraySize; ++i) 
        diffArray[i] = prefixMin[i - 1] - prefixMin[i];

    ll maxSuffixValue = 0, currentMinDiff = LLONG_MAX;

    for (int j = 2; j <= arraySize; ++j) {
        ll currentSuffixValue;
        
        if (j <= plateauPos) {
            if (j == 2) {
                currentSuffixValue = suffixSum[j] - elements[j];
            } else {
                currentMinDiff = min(currentMinDiff, diffArray[j - 1]);
                currentSuffixValue = suffixSum[j] - min(elements[j], currentMinDiff);
            }
        } else {
            currentSuffixValue = suffixSum[j];
        }
        
        maxSuffixValue = max(maxSuffixValue, currentSuffixValue);
    }

    cout << totalSum - maxSuffixValue << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCases;
    cin >> testCases;
    
    while (testCases--) {
        computeSolution();
    }
    
    return 0;
}