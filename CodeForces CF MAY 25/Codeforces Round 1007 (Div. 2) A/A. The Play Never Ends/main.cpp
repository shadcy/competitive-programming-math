#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int k;
        cin >> k;
        
        // The original spectator can spectate again in matches 1, 4, 7, 10...
        // These are matches where k % 3 == 1
        if (k % 3 == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}