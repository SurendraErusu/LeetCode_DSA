class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        
        dp[1][1] = grid[0][0];
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) continue;
                
                int up = dp[i-1][j] == INT_MAX ? INT_MAX : grid[i-1][j-1] + dp[i-1][j];
                int left = dp[i][j-1] == INT_MAX ? INT_MAX : grid[i-1][j-1] + dp[i][j-1];
                
                dp[i][j] = min(up, left);
            }
        }
        
        return dp[m][n];
    }
};
