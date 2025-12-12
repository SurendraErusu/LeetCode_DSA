class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1));
        //base case
        for (int i = 0; i <= amount; i++) {
            if (i%coins[0] == 0) {
                dp[0][i] =  i/coins[0];
            } else {
                dp[0][i] = 1e9;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                int pick = 1e9;
                if (j>=coins[i]) {
                   pick = 1 + dp[i][j-coins[i]];
                }
                int not_pick = dp[i-1][j];
                dp[i][j] = min (pick, not_pick);
            }
        }
        int ans = dp[n-1][amount];
        if (ans == 1e9) {
            return -1;
        }
        return ans;
    }
};