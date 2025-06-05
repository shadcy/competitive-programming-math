#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int totalOnes = 0;

        for (int i = 0; i < n; i++) {
            // Flip the i-th bit of s and count total 1s in the new string
            for (int j = 0; j < n; j++) {
                if (j == i) {
                    totalOnes += (s[j] == '0' ? 1 : 0);
                } else {
                    totalOnes += (s[j] == '1' ? 1 : 0);
                }
            }
        }

        cout << totalOnes << endl;
    }
    return 0;
}
