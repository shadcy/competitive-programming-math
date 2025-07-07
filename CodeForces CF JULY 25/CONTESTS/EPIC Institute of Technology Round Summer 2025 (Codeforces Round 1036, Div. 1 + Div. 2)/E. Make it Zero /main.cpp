/*
 * Author: Shreyash (shadcy)
 * Created: 2025-07-06
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
    vll a(n);
    ll total = 0;
    trav(x, a) {
        cin >> x;
        total += x;
    }

    if (total % 2 != 0) {
        cout << -1 << endl;
        return;
    }

    if (n == 2) {
        if (a[0] == a[1]) {
            cout << 1 << endl;
            cout << a[0] << " " << a[1] << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }

    vll prefix(n);
    prefix[0] = a[0];
    rep(i, 1, n) {
        prefix[i] = prefix[i-1] + a[i];
    }

    bool one_operation = false;
    int split_index = -1;
    ll half_total = total / 2;
    rep(i, 0, n-1) {
        if (prefix[i] == half_total) {
            one_operation = true;
            split_index = i;
            break;
        }
    }

    if (one_operation) {
        cout << 1 << endl;
        rep(i, 0, n) {
            cout << a[i];
            if (i < n-1) cout << " ";
            else cout << endl;
        }
    } else {
        int i0 = -1;
        rep(i, 0, n) {
            if (prefix[i] > half_total) {
                i0 = i;
                break;
            }
        }

        if (i0 < 1) {
            cout << -1 << endl;
            return;
        }

        if (a[i0] > half_total) {
            cout << -1 << endl;
            return;
        }

        ll d = 2 * prefix[i0] - total;
        ll half_d = d / 2;
        vll b(n, 0);
        b[i0] = half_d;
        ll need = half_d;
        rep(j, 0, i0) {
            if (need <= 0) break;
            ll take = min(a[j], need);
            b[j] = take;
            need -= take;
        }

        if (need > 0) {
            cout << -1 << endl;
        } else {
            cout << 2 << endl;
            rep(j, 0, n) {
                cout << b[j];
                if (j < n-1) cout << " ";
                else cout << endl;
            }
            rep(j, 0, n) {
                cout << a[j] - b[j];
                if (j < n-1) cout << " ";
                else cout << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}