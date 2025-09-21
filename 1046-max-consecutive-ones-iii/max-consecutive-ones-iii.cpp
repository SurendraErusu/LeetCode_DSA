class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, zero = 0;
        int max_len = INT_MIN;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r]==0) {
                zero++;
            }
            if (zero>k) {
                if (nums[l]==0) {
                    zero--;
                }
                l++;
            }
            if (zero<=k) {
                max_len = max(max_len, r-l+1);
            }
        }
        return max_len;
    }
};