class Solution {
public:

    int helperSubsetXORSum(int ind, vector<int> nums, int curXor) {
        if (ind == nums.size()) {
            return curXor;
        }
        int pick = helperSubsetXORSum(ind+1, nums, curXor^nums[ind]);
        int notPick = helperSubsetXORSum(ind+1, nums, curXor);
        return pick+notPick;
    }

    int subsetXORSum(vector<int>& nums) {
        return helperSubsetXORSum(0, nums, 0);
    }
};