#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isPossible(const string& s) {
    unordered_map<char, int> color;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (color.count(c)) {
            // Check if parity (even/odd index) matches assigned color
            if (color[c] != i % 2) return false;
        } else {
            // Assign color based on index parity
            color[c] = i % 2;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        if (isPossible(s)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
