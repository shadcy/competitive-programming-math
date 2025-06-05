#include <bits/stdc++.h>
using namespace std;

// Optimization
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

// Aliases
using ll = long long;
using vi = vector<int>;

// Macros
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)

// Function to abbreviate long strings
string abbreviate(const string& s) {
    if (s.size() > 10) {
        return s.front() + to_string(s.size() - 2) + s.back();
    }
    return s;
}

// Main Function
int main() {
    fast_io;

    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Number of strings
        vector<string> words(n);

        rep(i, 0, n) {
            cin >> words[i];
        }

        for (const auto& word : words) {
            cout << abbreviate(word) << "\n";
        }
    }

    return 0;
}
