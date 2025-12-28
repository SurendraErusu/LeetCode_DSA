class Solution {
public:
    void helper (vector<int>& nums, vector<vector<int>> &res, vector<int> &arr, int i) {
        if (i == nums.size()) {
            res.push_back(arr);
            return;
        }
        arr.push_back(nums[i]);
        helper(nums, res, arr, i+1);
        arr.pop_back();
        helper(nums, res, arr, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> arr;
    helper(nums, res, arr, 0);
    return res;
    }
};