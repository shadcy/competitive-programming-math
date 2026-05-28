/*
 * Author: Shreyash (shadcy)
 * Created: 2025-12-12
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
#define rep(i, a, b) for(int i = a; i < b; i++)
#define per(i, a, b) for(int i = a; i >= b; i--)
#define trav(x, v) for(auto& x : v)
#define setbits(x) __builtin_popcountll(x)
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const int MAXN = 2e5 + 5;

template<typename T> void read(T &x) { cin >> x; }
template<typename T> void read(vector<T> &v) { trav(x, v) cin >> x; }
template<typename T> void write(T x) { cout << x << endl; }
template<typename T> void write(vector<T> &v) { trav(x, v) cout << x << " "; cout << endl; }

ll power(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    a %= mod;
    while(b > 0) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

bool isPrime(ll n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(ll i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

vector<ll> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<ll> primes;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            primes.pb(i);
            for(ll j = (ll)i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}


/******************* TREE UTILITIES (CP SHORTCUTS) ********************/


struct Node {
  int data;
  Node *left, *right;
  //constructer
  Node(int val){
    data = val;
    left = right = NULL;
  }
};


// ---------- Input: Build graph tree (1-indexed) ----------
vector<vi> treeAdj;  
int n;

// reads n, then n-1 edges
void readTreeAdj() {
    cin >> n;
    treeAdj.assign(n+1, vi());
    rep(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        treeAdj[u].pb(v);
        treeAdj[v].pb(u);
    }
}

// ---------- BFS on a tree ----------
vi bfs(int start) {
    vi dist(n+1, -1);
    queue<int> q;

    q.push(start);
    dist[start] = 0;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v: treeAdj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

// ---------- DFS (for subtree size, tin/tout etc) ----------
const int MAXT = 200005;
int parentT[MAXT], depthT[MAXT], subSize[MAXT];
vi g[MAXT];

void dfs(int u, int p) {
    parentT[u] = p;
    subSize[u] = 1;

    for(int v : g[u]) {
        if(v == p) continue;
        depthT[v] = depthT[u] + 1;
        dfs(v, u);
        subSize[u] += subSize[v];
    }
}

// ---------- BINARY LIFTING LCA ----------
const int LOG = 20;
int up[MAXT][LOG];    // up[v][i] = 2^i parent

void buildLCA(int root = 1) {
    depthT[root] = 0;
    dfs(root, root);

    // initialize up table
    rep(v, 1, n+1) up[v][0] = parentT[v];

    rep(j, 1, LOG)
        rep(v, 1, n+1)
            up[v][j] = up[ up[v][j-1] ][j-1];
}

int lca(int a, int b) {
    if(depthT[a] < depthT[b]) swap(a, b);

    // lift 'a' up
    int diff = depthT[a] - depthT[b];
    rep(i, 0, LOG)
        if(diff & (1 << i))
            a = up[a][i];

    if(a == b) return a;

    // lift both together
    per(i, LOG-1, 0)
        if(up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }

    return parentT[a];
}

// ---------- BINARY TREE (Level Order Input) ----------
Node* buildBinaryTree() {
    int x;
    cin >> x;
    if(x == -1) return NULL;

    Node* root = new Node(x);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* cur = q.front(); q.pop();

        int l, r;
        cin >> l;
        if(l != -1) {
            cur->left = new Node(l);
            q.push(cur->left);
        }

        cin >> r;
        if(r != -1) {
            cur->right = new Node(r);
            q.push(cur->right);
        }
    }
    return root;
}

// ---------- Height of binary tree ----------
int heightBT(Node *root) {
    if(!root) return 0;
    return 1 + max(heightBT(root->left), heightBT(root->right));
}

void solve() {
    // Your solution here
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
    return 0;
}
