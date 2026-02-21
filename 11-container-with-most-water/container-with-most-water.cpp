class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int l = 0, r = height.size()-1;
        for (int i = 0; i < height.size(); i++) {
            while (l<r) {
               int length =  min(height[l],height[r]);
               int bredth = r-l;
               int area = length*bredth;
                max_area = max(area, max_area);

                if (height[l] > height[r]) {
                    r--;
                }
                else {
                    l++;
                }
            }
        }
        return max_area;
    }
};