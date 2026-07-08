/*
 * Author: Shreyash (shadcy)
 * Created: 2026-01-27
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

class inst{
    public:


    int maxofarr(vector<int> &nums){
     //check point, making manner work
    int max = INT_MIN;
    rep(i, 0, nums.size()){
        if(nums[i] > max){
            max = nums[i];
        }
    }
    return max;
    }


};
// void solve() {
//     // Your solution here
//     /*
//     We are given a permutation, mean we have exactly one element of each from 1 to n

//     now we have that permutation p, given.
//     we have to out the max lexical out ordered.

//     Can sorting works?
//     ig it wont, 
    
//     */

//     //main goal is to gt the max element at the front
//     //if alredy max is in the front, get the second best to the another after pos
//     //and so on....

//     int n;
//     cin>>n;
//     vi nums(n);
//     read(nums);

//     //we need an algo to get the left and the right in the proper manner
//     //manner : get the largest, and search to its left for the smallerst one and reverse the whole, whuck would also not work
//     // new manner : see it like a coloring problem, once we have a lrgest on the front, color it red, if not its black, get that max in the black and then reverse ti the next of red

//     //make manner work
//     inst obj;
//     //create an obj
//     vi sorted(n);
//     sorted = nums;
//     sort(all(sorted));

//     //now we have the order of 1, 2, 3rd and so on of the elements.
    
    



     
// }

void solve() {
    int n;
    cin >> n;
    vi p(n);
    read(p);

    // Find position of maximum element n
    int pos = -1;
    for(int i = 0; i < n; i++) {
        if(p[i] == n) {
            pos = i;
            break;
        }
    }

    if(pos != 0) {
        // Bring max to front
        reverse(p.begin(), p.begin() + pos + 1);
        write(p);
        return;
    }

    // max already at front, try next best
    // Find the first position where we can improve
    int idx = -1;
    for(int i = 1; i + 1 < n; i++) {
        if(p[i] < p[i + 1]) {
            idx = i;
            break;
        }
    }

    if(idx == -1) {
        // Already lexicographically maximum, forced operation
        reverse(p.begin(), p.begin()); // no-op
        write(p);
        return;
    }

    // Find max in suffix starting at idx+1
    int bestPos = idx + 1;
    for(int i = idx + 1; i < n; i++) {
        if(p[i] > p[bestPos]) {
            bestPos = i;
        }
    }

    reverse(p.begin() + idx, p.begin() + bestPos + 1);
    write(p);
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
