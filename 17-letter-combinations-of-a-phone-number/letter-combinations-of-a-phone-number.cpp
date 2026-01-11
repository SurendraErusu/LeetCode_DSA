class Solution {
public:
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};
    
    void helper(int i, vector<string> &res, string digits, string curr) {
        if (i == digits.size()) {
            res.push_back(curr);
            return;
        }
        string c = digitToChar[digits[i]-'0'];
        for (auto x : c) {
            helper(i+1, res, digits, curr+x);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        helper(0, res, digits, "");
        return res;
    }
};