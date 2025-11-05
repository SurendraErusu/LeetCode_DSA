class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int count = 0;
        int largest = 0;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        for (auto it : s) {
            if (s.find(it-1) == s.end()) {
                int x = it;
                count = 1;
                while (s.find(x+1) != s.end()) {
                    count++;
                    x++;
                }
                if (count>largest) {
                    largest = count;
                }
            }
        }
        return largest;
    }
};