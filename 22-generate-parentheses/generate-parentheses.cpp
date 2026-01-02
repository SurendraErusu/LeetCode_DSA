class Solution {
public:
    void helper(int open, int close, int n, vector<string>& res, string& ans) {
        if (open == n && close == n) {
            res.push_back(ans);
            return;
        }

        if (open < n) {
            ans+= "(";
            helper(open + 1, close, n, res, ans);
            ans.pop_back();
        }

        if (open > close) {
            ans+= ")";
            helper(open, close + 1, n, res, ans);
            ans.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string ans;
        helper(0, 0, n, res, ans);
        return res;
    }
};
