#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll maxCount(ll len, ll s, ll &ways) {
    ll best = 0;
    ways = 0;

    // Only need to check the first s possible starting positions
    for (ll start = 1; start <= s && start <= len; start++) {
        ll count = 1 + (start - 1) / s + (len - start) / s; 
        if (count > best) {
            best = count;
            ways = 1;
        } else if (count == best) {
            ways++;
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, s;
    cin >> n >> m >> s;

    ll waysRow, waysCol;
    ll maxRows = maxCount(n, s, waysRow);
    ll maxCols = maxCount(m, s, waysCol);

    // Number of starting positions = waysRow * waysCol
    cout << waysRow * waysCol << "\n";
    return 0;
}
