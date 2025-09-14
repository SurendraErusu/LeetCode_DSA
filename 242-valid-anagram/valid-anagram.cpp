class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        if (s.length() != t.length()) {
            return false;
        }
        for (int i = 0; i < s.length(); i++) {
            m1[s[i]]++;
            m2[t[i]]++;
        }
        return m1==m2;
    }
};