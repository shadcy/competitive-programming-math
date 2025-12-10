/*
 * Author: Shreyash (shadcy)
 * Created: 2025-10-30
 * Template: Competitive Programming
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define endl '\n'

int n;

bool has3Consecutive(vector<string>& g) {
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (j + 2 < n && g[i][j] == '#' && g[i][j+1] == '#' && g[i][j+2] == '#') 
                return true;
            if (i + 2 < n && g[i][j] == '#' && g[i+1][j] == '#' && g[i+2][j] == '#') 
                return true;
        }
    }
    return false;
}

bool isConnected(vector<string>& g) {
    int si = -1, sj = -1, cnt = 0;
    rep(i, 0, n) rep(j, 0, n) if (g[i][j] == '#') {
        cnt++;
        if (si == -1) { si = i; sj = j; }
    }
    if (cnt <= 1) return true;
    
    vector<vector<bool>> vis(n, vector<bool>(n));
    queue<pii> q;
    q.push({si, sj});
    vis[si][sj] = true;
    int visited = 1;
    
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
        rep(d, 0, 4) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && 
                g[nx][ny] == '#' && !vis[nx][ny]) {
                vis[nx][ny] = true;
                visited++;
                q.push({nx, ny});
            }
        }
    }
    return visited == cnt;
}

void solve() {
    cin >> n;
    vector<string> g(n);
    rep(i, 0, n) cin >> g[i];
    
    if (has3Consecutive(g)) {
        cout << "NO" << endl;
        return;
    }
    
    int blacks = 0;
    rep(i, 0, n) rep(j, 0, n) if (g[i][j] == '#') blacks++;
    
    if (blacks <= 1 || isConnected(g)) {
        cout << "YES" << endl;
        return;
    }
    
    // BFS on states
    map<vector<string>, bool> visited;
    queue<vector<string>> q;
    q.push(g);
    visited[g] = true;
    
    while (!q.empty()) {
        auto curr = q.front(); q.pop();
        
        rep(i, 0, n) {
            rep(j, 0, n) {
                if (curr[i][j] == '.') {
                    // Check if adjacent to black
                    bool adj = false;
                    if (i > 0 && curr[i-1][j] == '#') adj = true;
                    if (i < n-1 && curr[i+1][j] == '#') adj = true;
                    if (j > 0 && curr[i][j-1] == '#') adj = true;
                    if (j < n-1 && curr[i][j+1] == '#') adj = true;
                    
                    if (adj) {
                        curr[i][j] = '#';
                        if (!has3Consecutive(curr)) {
                            if (isConnected(curr)) {
                                cout << "YES" << endl;
                                return;
                            }
                            if (!visited[curr]) {
                                visited[curr] = true;
                                q.push(curr);
                            }
                        }
                        curr[i][j] = '.';
                    }
                }
            }
        }
    }
    
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}