#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n, rK, cK, rD, cD;
        cin >> n >> rK >> cK >> rD >> cD;
        
        bool sameRow = (rK == rD);
        bool sameCol = (cK == cD);
        
        // Case 1: Not aligned - Krug can potentially escape to corner
        if (!sameRow && !sameCol) {
            // Check if Krug is already at a corner or edge
            bool krugAtCorner = ((rK == 0 || rK == n) && (cK == 0 || cK == n));
            bool krugAtEdge = (rK == 0 || rK == n || cK == 0 || cK == n);
            
            if (krugAtCorner || krugAtEdge) {
                // Need to check if Doran can immediately catch
                long long chebDist = max(abs(rK - rD), abs(cK - cD));
                if (chebDist == 1) {
                    cout << 1 << "\n";
                } else {
                    cout << -1 << "\n";
                }   
            } else {
                // Krug not at edge but can escape
                cout << n << "\n";
            }
            continue;
        }
        
        // Case 2: Aligned on row or column
        long long survival;
        
        if (sameRow) {
            if (cK < cD) {
                survival = cK;
            } else {
                survival = n - cK;
            }
        } else {
            if (rK < rD) {
                survival = rK;
            } else {
                survival = n - rK;
            }
        }
        
        cout << survival << "\n";
    }
    
    return 0;
}