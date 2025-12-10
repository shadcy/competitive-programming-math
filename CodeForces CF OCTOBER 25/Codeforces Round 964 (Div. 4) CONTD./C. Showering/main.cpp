/*
 * Author: Shreyash (shadcy)
 * Created: 2025-10-03
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
const int lmN = 2e5 + 5;

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

// void solve()
// {
//     // Your solution here
//     int n, s, m;
//     cin >> n >> s >> m;

//     // this is the condition
//     //  we need to follow:

//     // n is the number of intervals : rep --> a, b

//     // s number of mins he'll require to washup

//     // m amount day has  (0, 1, 2, 3, 4, ......, m).
//     // can use iota for this

//     vector<int> ms(m, 0);
//     //  iota(ms.begin(), ms.end(), 0);
//     // forward iter first, last, start_val

//     // itll have 0, ...., m

//     rep(i, 0, n)
//     {
//         // run for number of intervals
//         int a, b;
//         cin >> a >> b;

//         rep(i, a, b)
//         {
//             ms[i] = 1;
//         }
//     }

//     // just find the riight interval if any ow print NO
//     //  write(ms);   //: Worked

//     // //create a window of s {0, 0, 0, .., s}
//     // vi ss(s, 0);

//     // //now check if this window exists in the ms array
//     int lm = 1, tm;
//     rep(i, 0, ms.size() - 1)
//     { // -1 to fuck the out-of-bounds case
//         if (ms[i] + ms[i + 1] == 0)
//         {
//             lm++;
//             tm = lm;
//         }
//         else
//         {
//             lm = 1; // to reset
//         }
//     }

//     if (tm >= s)
//     {
//         // yes
//         cout << "YES \n";
//     }
//     else
//     {
//         // no
//         cout << "NO \n";
//     }
// }

void solve()
{
    int n, s, m;
    cin >> n >> s >> m;

    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tasks[i].first >> tasks[i].second;
    }

    // Check before first task
    if (tasks[0].first >= s)
    {
        cout << "YES\n";
        return;
    }

    // Check gaps between tasks
    for (int i = 1; i < n; i++)
    {
        if (tasks[i].first - tasks[i - 1].second >= s)
        {
            cout << "YES\n";
            return;
        }
    }

    // Check after last task
    if (m - tasks[n - 1].second >= s)
    {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
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
