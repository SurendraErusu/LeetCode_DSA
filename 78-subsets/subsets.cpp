class Solution {
public:
    void subsetHelper(vector<vector<int>> &res, vector<int> &arr, vector<int>& 
    nums, int ind) {
        if (ind == nums.size()) {
            res.push_back(arr);
            return;
        }
        arr.push_back(nums[ind]);
        subsetHelper(res, arr, nums, ind+1);
        arr.pop_back();
        subsetHelper(res, arr, nums, ind+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> arr;
        subsetHelper(res,arr,nums,0);
        return res;
    }
};