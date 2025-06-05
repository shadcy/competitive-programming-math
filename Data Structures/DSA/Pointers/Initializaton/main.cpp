#include <bits/stdc++.h>
using namespace std;

// Optimization
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

//function for gcd calculation
int gcd(int a, int b) {
    while (b) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

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

// Main Function
int main() {
    fast_io;

// huffman coding is loss-less data compression technique
//follows prefix free coding scheme

//There are mainly 2 major parts in huffman coding
//1. Build a huffman tree with input characters
//2. Traverse the huffman tree an assign codes to charecters

// now i want to store the value and address of the some perticul;ar struuct to the same variable 
// how to do that
//huh
int val = 10;
int* rate = &val; //

cout<<" val - "<<*rate;
cout<<" ptr add - "<<&rate;

}
