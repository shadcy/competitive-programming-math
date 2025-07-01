/*
 * Author: Shreyash (shadcy)
 * Created: 2025-06-29
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
    //TL;DR i am a bastard
    int n;
    cin >> n;
    vi dials(n);
    rep(i, 0, n)
    {
        cin>>dials[i];
    }
    // this is n iter
    rep(i, 0, n)
    {
        int dial_input;
        string s;
        // input n
        cin >> dial_input;
        cin >> s;
        int d = 0, u = 0;
        // // bp  //nice bitch we are getting 0s in here took another 10 mins fucking jacked********
        //this is how ill go igm no! mf**********
        // rep(i, 0, n)
        // {
        //     cout << dials[i] << " ";
        // }
        // cout<<"\n";
        // // bp
        // lets add the logic here for each case
        rep(j, 0, dial_input)
        {
            if (s[j] == 'U')
            { // fucked here lost 10+ mins in here fuc******
                dials[i]--;
                // u++;
            }
            else
            {
                dials[i]++;
                // d++;
            }
        }
        // cout<<d<<" "<<u;
        // cout<<"\n";
        // dials[i] = (dials[i] + u) - d;
    }

    rep(i, 0, n)
    {
        if(dials[i] < 0){
            cout<<dials[i] + 10<<" ";
        }
        else if(dials[i] > 9){
            cout<<dials[i] - 10<<" ";
        }
        else{
            cout<<dials[i]<<" ";
        }
    }
    cout << "\n";
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
