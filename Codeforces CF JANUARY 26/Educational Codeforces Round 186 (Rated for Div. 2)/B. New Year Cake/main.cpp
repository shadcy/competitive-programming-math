/*
 * Author: Shreyash (shadcy)
 * Created: 2026-01-16
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
    long long a, b;
    cin >> a >> b;

    auto calc = [&](long long white, long long dark) {
        long long cur = 1;
        int layers = 0;
        bool useWhite = true;

        while (true)
        {
            if (useWhite)
            {
                if (white < cur) break;
                white -= cur;
            }
            else
            {
                if (dark < cur) break;
                dark -= cur;
            }
            layers++;
            cur *= 2;
            useWhite = !useWhite;
        }
        return layers;
    };

    int ans1 = calc(a, b); // white on top
    int ans2 = calc(b, a); // dark on top

    cout << max(ans1, ans2) << '\n';
}


// void solve()
// {
//     // Your solution here
//     int a, b;
//     cin >> a >> b;

//     // a is white choco, and b is dark choco
//     // brute force

//     int mx = max(a, b);
//     int mn = min(a, b);
//     int i = 1;
//     int layer1 = 0;
//     int layer2 = 0;
//     bool keep_going = true;
//     while (keep_going)
//     {
//         if (mn >= i)
//         {
//             mn = mn - i;
//             // suppose its layer1 1
//             layer1++;
//         }
//         else
//         {
//             keep_going = false;
//             break;
//         }
//         if (mx >= 2 * i)
//         {
//             mx = mx - 2 * i;
//             layer1++;
//         }
//         else
//         {
//             keep_going = false;
//             break;
//         }
//         i = 4 * i;
//     }
//      keep_going = true;
//     i = 1;
//     while (keep_going)
//     {
//         if (mx >= i)
//         {
//             mx = mx - i;
//             // suppose its layer1 1
//             layer2++;
//         }
//         else
//         {
//             keep_going = false;
//             break;
//         }
//         if (mn >= 2 * i)
//         {
//             mn = mn - 2 * i;
//             layer2++;
//         }
//         else
//         {
//             keep_going = false;
//             break;
//         }
//         i = 4 * i;
//     }

//     cout << max(layer1, layer2) << endl;
// }

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
