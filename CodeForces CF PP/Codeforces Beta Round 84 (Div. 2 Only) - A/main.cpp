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

    // SOL 1

    // i want to know if i can break an integer to array?
    // lets see how?
    // lets say we have a number n = 7447774; now i want to creeaate a array 
    // of sizeof(n) and that array has [7, 4, 4, 7, 7, 7, 4]
    // after this the question will be piece of cakkke
       


//     In C++, the size of an int is typically 4 bytes (on most systems). This means:
// 4 bytes=4×8=32 bits
// 4 bytes=4×8=32 bits

//     Since one bit is used for the sign (positive or negative), the range of a signed int is:
//     −2^31 to 2^31−1
//     −2^31 to 2^31−1 Which is:
//     −2,147,483,648 to 2,147,483,647
//     −2,147,483,648 to 2,147,483,647

// So, an int cannot store a number as large as 1000000000000000000 (10^18), because 10^18 is much larger than 2,147,483,647.

    // make sure we use long long and not int for the inputs more than 4byts
        ll n;
        cin>>n;
        int cnt =0;
        ll tmp =n;
       while (n%10 != n)
       {
        /* code */
        n=n/10;
        cnt+=1;
       }
       cnt = cnt +1;

       n = tmp;
         int arr[ cnt];
        for(int i=0;i<cnt ;i++){
           arr[i] = n%10;
           n/=10;
        }
         // now we sucessfully created a array of number n ; though its reversed bt should be good enough
      int luckey_number=0; // its not lucky
         for(int i=0;i<cnt ;i++){
           if(arr[i] == 4 || arr[i] == 7){
            luckey_number+=1;
           }
         }

         if(luckey_number == 4 || luckey_number == 7){
            cout<<"YES";
           }
           else{
            cout<<"NO";
           }


           
}
