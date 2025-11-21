class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[n] = true;
        for (int i = s.size()-1; i>= 0; i--) {
            for (int j = 0; j < wordDict.size(); j++) {
                int len = wordDict[j].size();
                if (i+len <= s.size() && wordDict[j] == s.substr(i,len)) {
                    dp[i] = dp[i+len];
                    //break;
                }
                if (dp[i]) break; 

            }
        }
        return dp[0];
    }
};