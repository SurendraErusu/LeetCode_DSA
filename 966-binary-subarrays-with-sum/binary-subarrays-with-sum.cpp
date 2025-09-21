class Solution {
public:
    int helper(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int l = 0, sum= 0, count = 0;
            for (int r = 0; r < nums.size(); r++) {
                sum = sum+nums[r];
                while (sum>goal) {
                    sum = sum-nums[l];
                    l++;
                }
                count = count+(r-l+1);
            }
            return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal-1);
    }
};