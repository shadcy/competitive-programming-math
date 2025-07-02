/*
 * Author: Shreyash (shadcy)
 * Created: 2025-06-08
 * Template: Competitive Programming
 * Description:
 *   Given an integer n, construct and print a specific sequence of numbers
 *   following a particular pattern, repeated for t test cases.
 */

#include <bits/stdc++.h>
using namespace std;

// Type Aliases
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<string> vs;

// Macros
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

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const int MAXN = 2e5 + 5;

// I/O Helper Functions
template<typename T> void read(T &x) { cin >> x; }
template<typename T> void read(vector<T> &v) { trav(x, v) cin >> x; }
template<typename T> void write(T x) { cout << x << endl; }
template<typename T> void write(vector<T> &v) { trav(x, v) cout << x << " "; cout << endl; }

// Utility Functions
ll power(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

vector<ll> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<ll> primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.pb(i);
            for (ll j = (ll)i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

// ------------------------ Main Logic Function ------------------------

/*
 * func(n):
 * Constructs a specific sequence of integers based on input n.
 * - Start with 2, 3
 * - Then alternately insert from ends towards center: (n, 4), (n-1, 5), ...
 * - Always end with 1
 * The goal is to create a sequence optimized for some undisclosed property (e.g. minimal adjacent differences, contest-specific requirement, etc.)
 */
void func(int n) {
    vi v;

    // Start with fixed values
    v.pb(2); 
    v.pb(3);

    // Initialize two pointers for mid-values
    int left = 4, right = n;

    // Alternately push from right and left ends
    while (left <= right) {
        v.pb(right--);      // Push from right
        if (left <= right)
            v.pb(left++);   // Then push from left
    }

    // End with 1 — required by problem
    v.pb(1);

    // Output the constructed sequence
    trav(x, v) cout << x << ' ';
    cout << endl;
}

// ------------------------ Driver Code ------------------------

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; 
    cin >> t;  // Number of test cases

    while (t--) {
        int n;
        cin >> n;
        func(n);
    }

    return 0;
}
