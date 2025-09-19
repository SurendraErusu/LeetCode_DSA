class Solution {
public:
    void  helperPermute(vector<int>& nums, vector<vector<int>> &res, int i) {
        if(i == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i],nums[j]);
            helperPermute(nums, res, i+1);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helperPermute(nums, res, 0);
        return res;
    }
};