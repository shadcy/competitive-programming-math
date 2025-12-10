/*
 * Author: Shreyash (shadcy)
 * Created: 2025-09-30
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
    int n, k;
    cin >> n >> k;

    vi vals(k);
    read(vals);

    // vi res(n);
    // sort(all(vals)); // for splitting max vals to the other vals taking O(logn)^2
    
    /*
    
        // for splitting
    int ops = 0;
    rep(i, 0, vals.size() - 1)
    {
        if (vals[i] == 1)
        {
            res.pb(1);
        }
        else
        {
            rep(i, 0, vals[i])
            {
                res.pb(1);
            }
            // cost for splitting / ops for splitting
            ops += vals[i] - 1; // for splitting
        }
    }

    // splitting for optimal case

    // for merge
    int mer = 0;
    rep(i, 0, vals.size() - 1)
    {
      mer += vals[i];

    }
    
    */

    

    // complexity earlier was O(n*logn).


    //current complexity is O(k)+O(n)
    int max =  INT_MIN, max_iter;
    rep(i, 0, k){
        if( vals[i] > max){
            max = vals[i];
            //we just need to erase the max at that 1 pos and should be only once
            //so perfect if we add that here
            //fu=huck only remove the max iter should not be in a loop
            max_iter = i;
        }
    }
    vals.erase(vals.begin() + max_iter); // remove only the max iter case; once

    // write(vals); // DEBUG
    int mer = 0;
    rep(i, 0, vals.size())
    {
        // if(vals[i] == max){
        //    continue; // skip
        //    // we are cooked if we have 2 equal maxes in vals we might miss the case
        //    // how to fix?
        // }
        // else{
             mer += vals[i] + (vals[i] - 1);
        // }
    }

   /*
    total ops required will be ops required for merger and splitting.
   */
    cout << mer << endl;
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
