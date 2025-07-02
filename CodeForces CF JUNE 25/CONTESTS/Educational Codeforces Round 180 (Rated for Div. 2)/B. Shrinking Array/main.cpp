#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int res = 0;
        int max_val = a.back();
        for (int k = 2; k < n; ++k) {
            int target = max_val - a[k];
            int i = 0;
            int j = k - 1;
            while (i < j) {
                if (a[i] + a[j] > target) {
                    res += j - i;
                    --j;
                } else {
                    ++i;
                }
            }
        }
        cout << res << endl;
    }
}

int main() {
    solve();
    return 0;
}