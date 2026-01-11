class Solution {
public:

    bool isPalindrome (string s, int i, int j) {
        while (i<=j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void helper (int i, vector<vector<string>> &res, vector<string> &arr, string s) {
        if (i == s.size()) {
            res.push_back(arr);
            return;
        }
        for (int j = i; j < s.size(); j++) {
            if (isPalindrome(s,i,j)) {
                arr.push_back(s.substr(i, j-i+1));
                helper(j+1, res, arr, s);
                arr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> arr;
        helper(0, res, arr, s);
        return res;
    }
};