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
    int test_cases;
    cin >> test_cases;
    
    while(test_cases--) {
        int array_size;
        cin >> array_size;
        vi elements(array_size);
        trav(x, elements) cin >> x;
        
        bool found = false;
        int first_pos = -1, second_pos = -1;
        
        rep(i, 0, array_size) {
            if(found) break;
            rep(j, i+1, array_size) {
                if(elements[i] > elements[j]) {
                    first_pos = i;
                    second_pos = j;
                    found = true;
                    break;
                }
            }
        }
        
        if(!found) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl << "2" << endl;
            cout << elements[first_pos] << " " << elements[second_pos] << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();
    
    return 0;
}