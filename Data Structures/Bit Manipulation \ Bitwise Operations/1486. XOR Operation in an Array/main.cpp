/*
 * Author: Shreyash (shadcy)
 * Created: 2025-12-08
 * Template: LeetCode C++
 *
 * Paste function inside class Solution and run.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        //array nums = nums[i] = start + 2i
        int res = 0;
        for(int i=0;i<n;i++){
            res ^= (start + 2 * i);
        }

        return res;
    }
};

int main() {
    // Local testing (optional)
    Solution sol;

    // Example:
    // cout << sol.someFunction() << endl;

    return 0;
}
