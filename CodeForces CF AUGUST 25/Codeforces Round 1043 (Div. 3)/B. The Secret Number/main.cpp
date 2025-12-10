/*
 * Author: Shreyash (shadcy)
 * Created: 2025-08-28
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

void solve()
{
    // Your solution here
    // from observing the test cases we can observe this cases only work when
    // all digits are equal and 0 o.w
    ull n;
    cin >> n;
    vector<ull> ans;

    ull pow10 = 10ULL; // 10^1
    while (true)
    {
        // denom = 1 + 10^k
        // if denom > n then no further k can work
        if (pow10 > (ULLONG_MAX - 1))
            break; // safety (not really needed here)
        ull denom = 1 + pow10;
        if (denom > n)
            break;

        if (n % denom == 0)
        {
            ans.push_back(n / denom);
        }

        // prepare next power of 10, but avoid overflow
        if (pow10 > n / 10)
            break; // next multiplication would exceed n or overflow
        pow10 *= 10ULL;
    }

    if (ans.empty())
    {
        cout << 0 << '\n';
    }
    else
    {
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (size_t i = 0; i < ans.size(); ++i)
        {
            if (i)
                cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int t = 1;
        cin >> t;

        while (t--)
        {
            solve();
        }

        return 0;
    }
