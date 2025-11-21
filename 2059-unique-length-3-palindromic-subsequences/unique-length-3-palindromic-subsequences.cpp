class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        for (int i = 0; i < s.size(); i++) {
            int ch = s[i]-'a';
            if (first[ch] == -1) {
                first[ch] = i;
            }
            last[ch] = i;
        }
        int ans = 0;
        
        for (int i = 0; i < 26; i++) {
            unordered_set<int> count;
            for (int j = first[i]+1; j < last[i]; j++) {
                count.insert(s[j]);
            }
            ans+=count.size();
        }
        return ans;
    }
};