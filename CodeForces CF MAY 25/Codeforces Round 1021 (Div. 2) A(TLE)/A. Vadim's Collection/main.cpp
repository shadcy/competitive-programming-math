#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isBeautiful(const string& s) {
    for (int i = 0; i < 10; ++i) {
        if (s[i] - '0' < 9 - i) {
            return false;
        }
    }
    return true;
}

string smallestBeautiful(string s) {
    sort(s.begin(), s.end()); // Start with the smallest lexicographic permutation
    do {
        if (isBeautiful(s)) return s;
    } while (next_permutation(s.begin(), s.end()));
    return s; // In theory, this should never be reached since input is guaranteed beautiful
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << smallestBeautiful(s) << '\n';
    }
    return 0;
}
