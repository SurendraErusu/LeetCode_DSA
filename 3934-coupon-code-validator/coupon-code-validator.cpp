class Solution {
public:
     bool isValidCode(const string& word) {
        if (word.empty()) return false;
        for (char c : word) {
            bool ok = (c >= '0' && c <= '9') ||
                      (c >= 'a' && c <= 'z') ||
                      (c >= 'A' && c <= 'Z') ||
                      (c == '_');
            if (!ok) return false;
        }
        return true;
    }
      
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<pair<string, string>> mp;
        for (int i = 0; i < n; i++) {
            if (isValidCode(code[i]) && businessLine[i] != "invalid" && isActive[i] == true) {
                mp.push_back({businessLine[i], code[i]});
            }
        }
        sort(mp.begin(), mp.end());
        vector<string> res;
        for (auto x : mp) {
            res.push_back(x.second);
        }
        return res;
    }
};