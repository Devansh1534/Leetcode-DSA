#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int num : nums) sum += num;
        
        if (S > sum || S < -sum) return 0;

        int offset = sum;
        vector<int> dp(2 * sum + 1, 0);
        
        dp[offset] = 1;
        
        for (int num : nums) {
            vector<int> next(2 * sum + 1, 0);
            for (int i = 0; i < dp.size(); ++i) {
                if (dp[i] != 0) {
                    next[i + num] += dp[i];
                    next[i - num] += dp[i];
                }
            }
            dp = next;
        }
        
        return dp[S + offset];
    }
};