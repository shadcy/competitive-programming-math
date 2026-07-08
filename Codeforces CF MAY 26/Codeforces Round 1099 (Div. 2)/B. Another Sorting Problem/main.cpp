#include <bits/stdc++.h>
using namespace std;
//i tried some but this solution is ddamn good only in On complexity
// https://chatgpt.com/share/6a0f289a-c8f0-8323-8ae1-150bc948fafa
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int k = 0;

    // maximum inversion gap
    for (int i = 0; i + 1 < n; i++) {
        k = max(k, a[i] - a[i + 1]);
    }

    // already sorted
    if (k == 0) {
        cout << "YES\n";
        return;
    }

    // dp[pos][taken]
    // taken = whether current element got +k
    bool dp[n][2];

    dp[0][0] = true;
    dp[0][1] = true;

    for (int i = 0; i < n - 1; i++) {
        dp[i + 1][0] = dp[i + 1][1] = false;

        for (int x = 0; x < 2; x++) {
            if (!dp[i][x]) continue;

            for (int y = 0; y < 2; y++) {
                int left = a[i] + x * k;
                int right = a[i + 1] + y * k;

                if (left <= right) {
                    dp[i + 1][y] = true;
                }
            }
        }
    }

    if (dp[n - 1][0] || dp[n - 1][1])
        cout << "YES\n";
    else
        cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}