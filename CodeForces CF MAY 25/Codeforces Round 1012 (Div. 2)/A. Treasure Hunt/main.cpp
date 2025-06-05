#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long x, y, a;
        cin >> x >> y >> a;
        
        long long total = 0;
        int day = 1;
        
        while (true) {
            if (day % 2 == 1) {
                // Little B's turn (odd days)
                total += x;
                if (2 * total > 2 * a + 1) {
                    cout << "NO\n";
                    break;
                }
            } else {
                // Little K's turn (even days)
                total += y;
                if (2 * total > 2 * a + 1) {
                    cout << "YES\n";
                    break;
                }
            }
            day++;
        }
    }
    
    return 0;
}