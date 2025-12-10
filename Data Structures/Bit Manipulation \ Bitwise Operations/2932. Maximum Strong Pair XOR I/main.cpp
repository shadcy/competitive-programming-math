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
    int maximumStrongPairXor(vector<int>& nums) {
        int max = INT_MIN;
        for(int i=0;i<nums.size();i++){
          for(int j=0;j<nums.size();j++){
            if(abs(nums[j] - nums[i]) <= min(nums[j], nums[i])){
                if(max <= (nums[j]^nums[i])){
                   max = (nums[j]^nums[i]);
                }
            }
          }
        }

        return max;
    }

};

int main() {
    // Local testing (optional)
    Solution sol;

    // Example:
    // cout << sol.someFunction() << endl;

    return 0;
}
