#include <iostream>
#include <cstdint>

using namespace std;

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        uint64_t n, l, r, k;
        cin >> n >> l >> r >> k;
        
        if (n % 2 == 1) {
            cout << l << '\n';
            continue;
        }
        
        if (n == 2) {
            cout << "-1\n";
            continue;
        }
        
        // Calculate the smallest power of 2 ≥ l
        uint64_t power_of_two = 1;
        while (power_of_two < l) {
            power_of_two <<= 1;
            if (power_of_two == 0) break; // Prevent overflow
        }
        
        // If l is already a power of two, we need the next one
        if ((power_of_two == l) && (power_of_two << 1) <= r && (power_of_two << 1) != 0) {
            power_of_two <<= 1;
        }
        
        if (power_of_two <= r && power_of_two != 0) {
            if (k < n - 1) {
                cout << l << '\n';
            } else {
                cout << power_of_two << '\n';
            }
        } else {
            cout << "-1\n";
        }
    }
}

int main() {
    solve();
    return 0;
}