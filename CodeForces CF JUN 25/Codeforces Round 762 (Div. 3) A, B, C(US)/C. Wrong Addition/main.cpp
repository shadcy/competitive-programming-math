#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        string a, s;
        cin >> a >> s;

        int i = a.size() - 1;
        int j = s.size() - 1;
        string b = "";
        bool possible = true;

        while (i >= 0) {
            if (j < 0) {
                possible = false;
                break;
            }

            int digitA = a[i] - '0';
            int digitS = s[j] - '0';

            if (digitS >= digitA) {
                b += (digitS - digitA) + '0';
                i--; j--;
            } else {
                if (j == 0) {
                    possible = false;
                    break;
                }
                int twoDigit = (s[j - 1] - '0') * 10 + (s[j] - '0');
                int diff = twoDigit - digitA;
                if (diff < 0 || diff > 9) {
                    possible = false;
                    break;
                }
                b += diff + '0';
                i--;
                j -= 2;
            }
        }

        // Copy remaining digits of s (for cases where s is longer)
        while (j >= 0) {
            b += s[j--];
        }

        if (!possible) {
            cout << -1 << endl;
        } else {
            // Remove leading zeros and reverse
            while (b.size() > 1 && b.back() == '0') b.pop_back();
            reverse(b.begin(), b.end());
            cout << b << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
