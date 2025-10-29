class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;  // one way to make 0 amount — take nothing

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
                if (dp[j] > INT_MAX) dp[j] = INT_MAX; // prevent overflow
            }
        }

        return dp[amount];
    }
};
