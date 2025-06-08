/*
 * Author: Shreyash (shadcy)
 * Created: 2025-06-08
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

template<typename T> void read(T &x) { cin >> x; }
template<typename T> void read(vector<T> &v) { trav(x, v) cin >> x; }
template<typename T> void write(T x) { cout << x << endl; }
template<typename T> void write(vector<T> &v) { trav(x, v) cout << x << " "; cout << endl; }

void solve() {
    int total, button_timer;
    cin >> total >> button_timer;
    
    vector<int> d(total);
    for (int i = 0; i < total; i++) {
        cin >> d[i];
    }
    

    vector<int> closed;
    for (int i = 0; i < total; i++) {
        if (d[i] == 1) {
            closed.push_back(i + 1);
        }
    }
    

    if (closed.empty()) {
        cout << "YES" << endl;
        return;
    }
    

    int presstime = closed[0] - 1;

    int end = presstime + button_timer;
    
    bool pass = true;
    for (int pos : closed) {
        if (pos > end) {
            pass = false;
            break;
        }
    }
    
    cout << (pass ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}