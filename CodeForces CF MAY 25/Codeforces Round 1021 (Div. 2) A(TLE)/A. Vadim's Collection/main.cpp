#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solve_beautiful_phone(string s) {
    // Convert string to vector of integers
    vector<int> digits;
    for (char c : s) {
        digits.push_back(c - '0');
    }
    
    // Sort digits to make it easier to find smallest valid digits
    sort(digits.begin(), digits.end());
    
    string result = "";
    vector<bool> used(10, false);  // Track which digits we've used
    
    // For each position (0-indexed), find smallest valid digit
    for (int pos = 0; pos < 10; pos++) {
        int min_required = 9 - pos;  // Minimum digit required at this position
        
        // Find the smallest unused digit that satisfies the constraint
        for (int i = 0; i < 10; i++) {
            if (!used[i] && digits[i] >= min_required) {
                result += to_string(digits[i]);
                used[i] = true;
                break;
            }
        }
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        cout << solve_beautiful_phone(s) << endl;
    }
    
    return 0;
}