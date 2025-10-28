class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }

        if (sum%2 != 0) {return false;}

        int t = sum/2;
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool> (t+1, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if(nums[0] < t) nums[0] = true;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= t; j++) {
                bool pick = false;
                if (nums[i] <= j) {
                    pick = dp[i-1][j-nums[i]];
                }  
                bool not_pick = dp[i-1][j];
                dp[i][j] = ( pick || not_pick);
            }
        }
        return dp[n-1][t];

    }
};