/*
 * Author: Shreyash (shadcy)
 * Created: 2026-01-05
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

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    ll sum = 0;
    for(int i = 2; i <= n; i++)
        sum += abs(a[i] - a[i-1]);

    ll ans = min(
        sum - abs(a[2] - a[1]), // CASE A : remove the start
        sum - abs(a[n] - a[n-1]) // CASE B remove the end
    );

    for(int i = 2; i < n; i++) {
        //CASE C : remove the middle
        ans = min(ans,
            sum
            - abs(a[i] - a[i-1]) // remove left
            - abs(a[i+1] - a[i]) //remove right
            + abs(a[i+1] - a[i-1]) //add new
        );
    }

    cout << ans << endl;
}


// void solve() {
//     // (Without DP)
//     //This is an optimization problem (DP for sure)
//     //mentioned in the tag as well


//     //formally we want to minimize (summation(bi - bi+1))
//     int n;
//     cin>>n;

//     vi nums(n);
//     read(nums);
    
//     //Provided, lets go with the brute/greedy method first
//     int tot_sum = 0;
//     //we can only skip upto one floor, lets just remove the max of the
//     //as its a max one contrbuting to high value of the time as its abs()
//     rep(i, 0, nums.size()){
//      tot_sum += nums[i];
//     }
//     int max = INT16_MIN;
//     int pos;
//     rep(i, 0, nums.size()){
//         if(nums[i]> max){
//             max = nums[i];
//             pos = i;
//         }
//     }
//     nums.erase(nums.begin() + pos);// remove element at the given pos
//     // here we have the max
//     // now use this as a key and remove it from the array
//     int res = 0;
//     rep(i, 0, nums.size()-1){
//        res += abs(nums[i] - nums[i+1]);
//     }

//     cout<<min(res, tot_sum)<<endl;
    
// }

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
