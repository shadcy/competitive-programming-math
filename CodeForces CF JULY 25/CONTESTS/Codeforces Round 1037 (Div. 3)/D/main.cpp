/*
 * Author: Shreyash (shadcy)
 * Created: 2025-07-17
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
typedef vector<array<ll, 3>> va;

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

ll power(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    a %= mod;
    while(b > 0) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

bool isPrime(ll n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(ll i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

vector<ll> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<ll> primes;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            primes.pb(i);
            for(ll j = (ll)i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

void solve() {
    // Your solution here
       int n;
    ll k;
    cin >> n >> k;
    
    va cs(n);
    rep(i, 0, n) {
        cin >> cs[i][0] >> cs[i][1] >> cs[i][2];
    }
    
    ll an = k;
    
    if (n <= 18) {
        function<void(ll, int)> df = [&](ll cn, int m) {
            an = max(an, cn);
            
            rep(i, 0, n) {
                if (m & (1 << i)) continue;
                
                if (cn >= cs[i][0] && cn <= cs[i][1]) {
                    df(cs[i][2], m | (1 << i));
                }
            }
        };
        
        df(k, 0);
    } else {
        ll c1 = k;
        vector<bool> u1(n, false);
        
        while (true) {
            int bi = -1;
            ll bc = c1;
            
            rep(i, 0, n) {
                if (u1[i]) continue;
                
                if (c1 >= cs[i][0] && c1 <= cs[i][1]) {
                    if (cs[i][2] > bc) {
                        bc = cs[i][2];
                        bi = i;
                    }
                }
            }
            
            if (bi == -1) break;
            
            u1[bi] = true;
            c1 = bc;
        }
        
        an = max(an, c1);
        
        vi od(n);
        iota(all(od), 0);
        sort(all(od), [&](int i, int j) {
            return cs[i][2] > cs[j][2];
        });
        
        ll c2 = k;
        vector<bool> u2(n, false);
        
        trav(idx, od) {
            if (c2 >= cs[idx][0] && c2 <= cs[idx][1]) {
                u2[idx] = true;
                c2 = cs[idx][2];
            }
        }
        
        an = max(an, c2);
        
        rep(st, 0, min(n, 10)) {
            if (k >= cs[st][0] && k <= cs[st][1]) {
                ll c3 = cs[st][2];
                vector<bool> u3(n, false);
                u3[st] = true;
                
                while (true) {
                    int bi = -1;
                    ll bc = c3;
                    
                    rep(i, 0, n) {
                        if (u3[i]) continue;
                        
                        if (c3 >= cs[i][0] && c3 <= cs[i][1]) {
                            if (cs[i][2] > bc) {
                                bc = cs[i][2];
                                bi = i;
                            }
                        }
                    }
                    
                    if (bi == -1) break;
                    
                    u3[bi] = true;
                    c3 = bc;
                }
                
                an = max(an, c3);
            }
        }
    }
    
    cout << an << endl;
    
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
