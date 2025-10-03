class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& image, int row, int col, int color, int startColor) {
        if (row < 0 || row >= image.size() || col < 0 || col>= image[0].size() || 
        image[row][col] != startColor) {
            return;
        }
        image[row][col] = color;
        for (int i = 0; i< 4; i++) {
            dfs(image, row+dir[i][0], col+dir[i][1], color, startColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startColor = image[sr][sc];
        if (startColor == color) return image; 
        dfs(image, sr, sc, color, startColor);
        return image;
    }
};