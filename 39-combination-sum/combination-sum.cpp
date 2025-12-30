class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>> &res, vector<int> &arr, 
    int target, int i) {
        if (target == 0) {
                res.push_back(arr);
                return;
            }
        if (i == nums.size()) {
            return;
        }
        if (nums[i] <= target) {
            arr.push_back(nums[i]);
            helper(nums, res, arr, target-nums[i], i);
            arr.pop_back();
        }
        helper(nums, res, arr, target, i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> arr;
        helper(candidates, res, arr, target, 0);
        return res;
    }
};