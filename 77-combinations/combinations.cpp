class Solution {
public:
    void helper(int i, int k, const vector<int>& nums,
                vector<vector<int>>& res, vector<int>& arr) {
        if ((int)arr.size() > k) return; // optional prune

        if (i == (int)nums.size()) {
            if ((int)arr.size() == k) res.push_back(arr);
            return;
        }

        arr.push_back(nums[i]);
        helper(i + 1, k, nums, res, arr);
        arr.pop_back();

        helper(i + 1, k, nums, res, arr);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        nums.reserve(n);
        for (int x = 1; x <= n; x++) nums.push_back(x);

        vector<vector<int>> res;
        vector<int> arr;
        helper(0, k, nums, res, arr);
        return res;
    }
};
