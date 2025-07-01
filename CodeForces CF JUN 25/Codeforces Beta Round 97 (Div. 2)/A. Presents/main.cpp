/*
 * Author: Shreyash (shadcy)
 * Created: 2025-06-25
 * Template: Competitive Programming
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<string> vs;

#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define F first
#define S second
#define rep(i, a, b) for(int i = a; i < b; i++)
#define per(i, a, b) for(int i = a; i >= b; i--)
#define trav(x, v) for(auto& x : v)
#define setbits(x) __builtin_popcountll(x)
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const int MAXN = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vi nums(n);
    vi res(n);
    
    // Read input using 0-based indexing
    rep(i, 0, n) {
        cin >> nums[i];
    }
    
    // Process the permutation
    rep(i, 0, n) {
        res[nums[i] - 1] = i + 1;  // Adjust for 1-based output
    }
    
    // Output the result
    rep(i, 0, n) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    // cin >> t;  // Uncomment if multiple test cases
    
    while(t--) {
        solve();
    }
    
    return 0;
}