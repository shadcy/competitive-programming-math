/*
 * Author: Shreyash (shadcy)
 * Created: 2025-10-29
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
    int n, k, x;
    cin >> n >> k >> x;
    vi pos(n);
    rep(i, 0, n) {
        cin >> pos[i];
    }
    //This is elo ma
     
    //now we have the pos of people around 0, x (guranteed from the question)
    // and number of pos empty

    // i can actually have number of empty pos here
    //if number of empty pos == k then  print the empos array


    //if the number of empty pos < k then we have to somehow start with the midpoint
    //of the epty positions and get the vlue with the min cost / max dist


    // if nummber of empty pos > k then (print all the empty pos) + fill with(any exisiting pos) will surely work


    sort(all(pos));
    

    set<int> upos(all(pos));
    vi spos(all(upos));
    
    // place teleports to maximize the minimum distance
    // Find all gaps and place teleports in middle of largest gaps
    
    vector<pair<int, pii>> gaps; // {gap_size, {left, right}}
    
    // Add gap from 0 to first friend
    if(sz(spos) > 0 && spos[0] > 0) {
        gaps.pb({spos[0], {0, spos[0]}});
    }
    
    // Add gaps between consecutive friends
    rep(i, 0, sz(spos) - 1) {
        int gap = spos[i + 1] - spos[i];
        if(gap > 0) {
            gaps.pb({gap, {spos[i], spos[i + 1]}});
        }
    }
    
    // Add gap from last friend to x
    if(sz(spos) > 0 && spos.back() < x) {
        gaps.pb({x - spos.back(), {spos.back(), x}});
    }
    
    // Sort gaps by size (largest first)
    sort(rall(gaps));
    
    vi result;
    
    // Place teleports in the middle of largest gaps
    int placed = 0;
    for(auto &gap : gaps) {
        if(placed >= k) break;
        int left = gap.S.F;
        int right = gap.S.S;
        int mid = (left + right) / 2;
        result.pb(mid);
        placed++;
    }
    
    // If we still need more teleports, place them at arbitrary valid positions
    set<int> used(all(result));
    int cur = 0;
    while(placed < k) {
        while(used.count(cur)) cur++;
        if(cur <= x) {
            result.pb(cur);
            used.insert(cur);
            placed++;
            cur++;
        }
    }
    
    // Output result
    trav(p, result) {
        cout << p << " ";
    }
    cout << endl;
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