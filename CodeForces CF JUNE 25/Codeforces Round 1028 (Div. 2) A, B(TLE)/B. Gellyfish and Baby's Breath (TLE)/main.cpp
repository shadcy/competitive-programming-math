/*
 * Author: Shreyash (shadcy)
 * Created: 2025-06-05
 */

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> p, q;

        // inputs for p
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            p.push_back(x);
        }

        // inputs for q
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            q.push_back(x);
        }

        // solving for the input
        for (int i = 0; i < n; i++) {
            int res, max_val = 0;
            for (int j = 0; j <= i; j++) {
                res = pow(2, p[j]) + pow(2, q[i - j]);
                if (res > max_val) {
                    max_val = res;
                }
            }
            cout << max_val << " ";
        }
        cout << endl;
    }
}
