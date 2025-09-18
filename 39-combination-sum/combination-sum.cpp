class Solution {
public:

    void helperCombinationSum (vector<int>& candidates, int target,
    vector<vector<int>> &res, vector<int> &arr, int ind) {
        if (target == 0) {
            res.push_back(arr);
            return;
        }
        if (ind == candidates.size()) {
            return;
        }
        if (target>=candidates[ind]) {
            arr.push_back(candidates[ind]);
            helperCombinationSum(candidates, target-candidates[ind], res, arr, 
            ind);
            arr.pop_back();
        }
        helperCombinationSum(candidates, target, res, arr, ind+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> arr;
        helperCombinationSum(candidates, target, res, arr, 0);
        return res;
    }
};