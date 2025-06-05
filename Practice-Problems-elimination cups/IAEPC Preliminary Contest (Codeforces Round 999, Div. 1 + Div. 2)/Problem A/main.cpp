#include <bits/stdc++.h>
using namespace std;

// Optimization
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

// Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

// Macros
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) (int)(v).size()
#define ff first
#define ss second
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i++)
#define debug(x) cerr << #x << " = " << x << endl

// Constants
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ld EPS = 1e-9;
const int dx[4] = {1, 0, -1, 0}; // Directions for grid problems
const int dy[4] = {0, 1, 0, -1};

// Utilities
template<typename T> void print_vector(const vector<T>& v) { for (auto& x : v) cout << x << " "; cout << "\n"; }
template<typename T> void input_vector(vector<T>& v) { for (auto& x : v) cin >> x; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll mod_add(ll a, ll b, ll m = MOD) { return ((a % m) + (b % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m = MOD) { return ((a % m) * (b % m) + m) % m; }
ll mod_sub(ll a, ll b, ll m = MOD) { return ((a % m) - (b % m) + m) % m; }

int calculatePoints(vector<int> &a) {
    vector<int> even, odd;
    for (int num : a) {
        if (num % 2 == 0)
            even.push_back(num);
        else
            odd.push_back(num);
    }

    // Sort both arrays in descending order
    sort(even.rbegin(), even.rend());
    sort(odd.rbegin(), odd.rend());

    // Add even numbers first, then odd numbers
    long long sum = 0;
    int points = 0;

    for (int num : even) {
        sum += num;
        if (sum % 2 == 0) {
            points++;
            while (sum % 2 == 0) sum /= 2; // Divide until it becomes odd
        }
    }

    for (int num : odd) {
        sum += num;
        if (sum % 2 == 0) {
            points++;
            while (sum % 2 == 0) sum /= 2; // Divide until it becomes odd
        }
    }

    return points;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << calculatePoints(a) << endl;
    }
    return 0;
}
