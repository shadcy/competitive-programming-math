/*
 * Author: Shreyash (shadcy)
 * Created: 2026-01-18
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
//helper

bool Crash(vector<int>&nums, int thr){
   rep(i, 0, nums.size()){
    if(nums[i] > thr){
        return true;
    }
   }
   return false;
}

/*
TLE version O(n*m)
*/

// void solve() {
//     // Your solution here
//     //firest line
//     int n, m, h;
//     cin>>n>>m>>h;
//     //sec line
//     vi vec(n);
//     read(vec);
//     //third
//     vi def(n); //default
//     def = vec; // in case program crashed 
//     //new out = def

//     rep(i, 0, m){
//         //m ops for the vector vec
//         int idx, inc; // this is to track index and incrementing by the val
//         cin>>idx>>inc;
//         vec[idx - 1] += inc; // as its 1 indexed, -1 is necessary
//         if(Crash(vec, h)){
//             //if true --> program crashed
//             //return to default
//             vec = def;
//         }  
//     }

//     write(vec);


// }


// void solve() {
//     int n, m, h;
//     cin >> n >> m >> h;
    
//     vi def(n);
//     read(def);
    
//     vi vec = def;
    
//     rep(i, 0, m) {
//         int idx, inc;
//         cin >> idx >> inc;
//         idx--; //asthe ops are considering 1 indexed
        
//         vec[idx] += inc;
        
//         bool crashed = false;
//         rep(j, 0, n) {
//             if(vec[j] > h) {
//                 crashed = true;
//                 break;
//             }
//         }
        
//         if(crashed) {
//             vec = def;
//         }
//     }
    
//     write(vec);
// }


// void solve() {
//     int n, m, h;
//     cin >> n >> m >> h;
    
//     vi def(n);
//     read(def);
    
//     vi vec = def;
    
//     rep(i, 0, m) {
//         int idx, inc;
//         cin >> idx >> inc;
//         idx--; 
        

//         if(vec[idx] + inc > h) {
        
//             vec = def;
//         } else {
    
//             vec[idx] += inc;
//         }
//     }
    
//     write(vec);
// }

void solve() {
    int n, m;
    ll h;
    cin >> n >> m >> h;
    
    vll base(n);
    read(base);
    
    vll cur = base;     
    vi t(n, -1);       
    int ct = -1; 

    rep(i, 0, m) {
        int idx;
        ll inc;
        cin >> idx >> inc;
        idx--; 

       
        if(t[idx] < ct) {
            cur[idx] = base[idx];
        }

        if(cur[idx] + inc > h) {
            ct = i; 
        } else {
            cur[idx] += inc;
            t[idx] = i;  
        }
    }

    rep(i, 0, n) {
        if(t[i] < ct) {
            cur[i] = base[i];
        }
    }
    
    write(cur);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
    return 0;
}
