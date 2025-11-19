class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int ans = original;
        unordered_map<int,int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }
        while (mp.find(original) != mp.end()) {
            ans = 2*original;
            original = ans;
        }
        return ans;
    }
};