/*
 * Author: Shreyash (shadcy)
 * Created: 2025-07-01
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

template<typename T>
void read(T &x) { cin >> x; }
template<typename T>
void read(vector<T> &v) { trav(x, v) cin >> x; }
template<typename T>
void write(T x) { cout << x << endl; }
template<typename T>
void write(vector<T> &v) { trav(x, v) cout << x << " "; cout << endl; }

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
    int n;
    cin >> n;
    
    //a + b ≡ 3 (mod 4) this ass will only do........(0)
    // a + b % 4 == 3 ?

    // the actual pairs we can have are 
    // (0, 3), (3, 0), (1, 2), (2, 1).

    // as 0, 1, 2, 3 / 4 == 0 with the same number as a reminder
    int count[4] = {0};
    for(int i = 0; i < n; i++) {
        count[i % 4]++;
    }
    // the motherfucking pattern we got here is
        //   g0: 0, 4, 8, 12... (rem 0)
        //   g1: 1, 5, 9, 13... (rem 1)
        //   g2: 2, 6, 10, 14... (rem 2)
        //   g3: 3, 7, 11, 15... (rem 3)


        // as 0, 3 and 1, 2 groups can be only paired..........ref(0)

    int pairs_03 = min(count[0], count[3]);
    // g0 is paired to g3 only
    int pairs_12 = min(count[1], count[2]);
    //g1 is paired to g2 only

    int unpaired = (count[0] - pairs_03) + (count[3] - pairs_03) + 
                   (count[1] - pairs_12) + (count[2] - pairs_12);
    

    int total = pairs_03 + pairs_12;
    
   //game theory?
    if(unpaired > 0 || total % 2 == 1) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
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