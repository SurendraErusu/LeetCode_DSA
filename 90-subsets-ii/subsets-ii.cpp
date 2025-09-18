class Solution {
public:

    void helperSubsetsWithDup(vector<int>& nums, vector<int> &arr, 
vector<vector<int>> &res, int i) {
       
        res.push_back(arr);
        for (int j = i; j < nums.size(); j++) {
            if (j>i && nums[j] == nums[j-1]) {
                continue;
            }
            arr.push_back(nums[j]);
            helperSubsetsWithDup(nums, arr, res, j+1);
            arr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> arr;
        helperSubsetsWithDup(nums, arr, res, 0);
        return res;
    }
};