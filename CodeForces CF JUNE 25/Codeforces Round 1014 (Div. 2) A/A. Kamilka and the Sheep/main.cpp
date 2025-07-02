#include <iostream>
#include <vector>
#include <climits> // for INT_MAX and INT_MIN
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> list(n);

        for (int i = 0; i < n; i++) {
            cin >> list[i];
        }

        int min_val = INT_MAX, max_val = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (list[i] > max_val) {
                max_val = list[i];
            }
            if (list[i] < min_val) {
                min_val = list[i];
            }
        }

        cout << max_val - min_val << endl;
    }

    return 0;
}
