/*
 * Author: Shreyash (shadcy)
 * Created: 2025-07-05
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

// void solve() {
//     int n;
//     cin >> n;
//     vi nums(n);
//     read(nums);
//     sort(nums.begin(), nums.end());

//     bool ok = false;
//     do {
//         if (n == 2) {
//             ok = true;
//             break;
//         }
//         ll r_num = nums[1], r_den = nums[0];
//         bool gp = true;
//         for (int i = 1; i < n - 1; i++) {
//             if (1LL * nums[i + 1] * r_den != 1LL * nums[i] * r_num) {
//                 gp = false;
//                 break;
//             }
//         }
//         if (gp) {
//             ok = true;
//             break;
//         }
//     } while (next_permutation(nums.begin(), nums.end()));

//     cout << (ok ? "Yes" : "No") << endl;
// }


bool canFormGP(vll &a) {
    int n = a.size();
    sort(a.begin(), a.end());

    if (n <= 2) return true;

    // All zeros case
    if (a[0] == 0) {
        for (ll x : a)
            if (x != 0) return false;
        return true;
    }

    ll r_num = a[1], r_den = a[0]; // ratio as fraction

    for (int i = 1; i < n - 1; i++) {
        if (a[i] == 0) return false; // can't divide by zero
        if (a[i + 1] * r_den != a[i] * r_num) return false;
    }

    return true;
}

void solve() {
    int n;
    cin >> n;
    vll a(n);
    for (ll &x : a) cin >> x;

    cout << (canFormGP(a) ? "Yes" : "No") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
