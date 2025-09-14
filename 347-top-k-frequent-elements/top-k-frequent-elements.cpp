class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
        vector<int> res;
        for (auto i : nums) {
            mp[i]++;
        }
        for (pair<int,int> p : mp) {
            min_heap.push({p.second, p.first});
            if (min_heap.size()>k) {
                min_heap.pop();
            }
        }
        while(!min_heap.empty()) {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }

        return res;
    }
};