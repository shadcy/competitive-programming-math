/*
 * Author: Shreyash (shadcy)
 * Created: 2026-01-18
 * Template: Competitive Programmin_eleg
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
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define trav(x, v) for (auto &x : v)
#define setbits(x) __builtin_popcountll(x)
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const int MAXN = 2e5 + 5;

template <typename T>
void read(T &x) { cin >> x; }
template <typename T>
void read(vector<T> &v) { trav(x, v) cin >> x; }
template <typename T>
void write(T x) { cout << x << endl; }
template <typename T>
void write(vector<T> &v)
{
    trav(x, v) cout << x << " ";
    cout << endl;
}

ll power(ll a, ll b, ll mod = MOD)
{
    ll res = 1;
    a %= mod;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

vector<ll> sieve(int n)
{
    vector<bool> is_prime(n + 1, true);
    vector<ll> primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            primes.pb(i);
            for (ll j = (ll)i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

int mex(const vi &a)
{
    int n = a.size();
    vector<bool> seen(n + 1, false);

    for (int x : a)
    {
        if (0 <= x && x <= n)
            seen[x] = true;
    }
    // rep(i, 0, n+1)
    for (int i = 0; i <= n; i++)
    {
        if (!seen[i])
            return i;
    }
    return n + 1; // otherwise if no match, edge case
}

void solve() {
    // Your solution here
    int n;
    cin >> n;
    vi nums(n);
    read(nums);
    
    // we somehow beed to optimize the thing/array to its lowest
    // the min_ele mex possible for the array is 0
    // so what we gonna do;
    // choose the x such that the min_ele numbers --> 0
    // and calculate the mex
    //do shit
    /* Choosing X
       We need to try shifting by -ai for each element
       This makes that element equal to 0
       Then calculate MEX and take maximum across all choices
    */
    
    int ans = 0;
    set<int> uvals(all(nums));
    
    for (int val : uvals) {
        vi shift(n);
        rep(i, 0, n) {
            shift[i] = nums[i] - val;
        }
        ans = max(ans, mex(shift));
    }
    
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
