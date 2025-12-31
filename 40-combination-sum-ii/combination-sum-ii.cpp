class Solution {
public:

    void helper(int i, vector<int>& candidates, int target, vector<vector<int>> &res, 
    vector<int> &arr) {
        if (target == 0) {
            res.push_back(arr);
        }
        for (int j = i; j < candidates.size(); j++) {
            if (j>i && candidates[j] == candidates[j-1]) continue;
            if (candidates[j] > target) break;
            arr.push_back(candidates[j]);
            helper(j+1, candidates, target-candidates[j], res, arr);
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> arr;
        sort(candidates.begin(), candidates.end());
        helper(0, candidates, target, res, arr);
        return res;
    }
};