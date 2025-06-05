#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Sort array in descending order
        sort(a.begin(), a.end(), greater<long long>());

        // Compute prefix sums of the largest k elements
        vector<long long> res(n);
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            res[i] = sum;
        }

        // Output the result
        for (int i = 0; i < n; ++i) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
