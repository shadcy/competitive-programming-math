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

// Main Function
int main() {
    fast_io;

    int T;
    cin >> T; // Number of test cases
    while (T--) {
        // Code goes here
        int a , b;
        cin>>a>>b;



        // Solution with TLE

        // int moves = 0;
        // while(a%b != 0){
        //        a+=1;
        //        moves++;
        // }
        // cout<<moves<<endl;


        //Optimal Solution

        if(a%b == 0) cout<<0<<endl;
        else{ 
        int moves = b - (a % b); 
        cout<<moves<<endl;
        }
        


    }

    return 0;
}
