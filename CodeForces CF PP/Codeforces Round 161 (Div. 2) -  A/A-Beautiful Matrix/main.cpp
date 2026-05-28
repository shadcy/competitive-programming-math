#include <bits/stdc++.h>
using namespace std;

bool is_valid_timur(const string& s) {
    if (s.length() != 5) return false;

    string sorted_s = s;
    sort(sorted_s.begin(), sorted_s.end());

    string correct = "Timur";
    sort(correct.begin(), correct.end());

    // Check if sorted letters match
    if (sorted_s != correct) return false;

    // Ensure exactly one 'T' and the rest lowercase
    int count_T = count(s.begin(), s.end(), 'T');
    int count_t = count(s.begin(), s.end(), 't'); // for lowercase 't'

    return count_T == 1 && count_t == 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        if (is_valid_timur(s)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
