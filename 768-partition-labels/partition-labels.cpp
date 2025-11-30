class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]] = i;
        }
        int max_count = 0;
        int c = 0;
        vector<int> ans;
        for (int i = 0; i < s.size(); i++) {        
            max_count = max(max_count, mp[s[i]]);
            c++;
            if (i == max_count) {
                ans.push_back(c);
                c = 0;
            }
        }
        return ans;
    }
};