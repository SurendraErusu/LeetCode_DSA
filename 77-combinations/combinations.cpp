class Solution {
public:

    void helper (int i, int k, vector<int> &nums, vector<vector<int>> &res, 
    vector<int> &arr) {
        if (i == nums.size()) {
            if (arr.size() == k) {
                res.push_back(arr);
            }
            return;
        }
        arr.push_back(nums[i]);
        helper(i+1, k, nums, res, arr);
        arr.pop_back();
        helper(i+1, k, nums, res, arr);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        vector<int> arr;
        vector<vector<int>> res;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        helper(0, k, nums, res, arr);
        return res;
    }
};