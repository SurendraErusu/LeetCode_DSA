class Solution {
public:
    vector<vector<int>> dir = {{0,-1}, {-1,0}, {0,1}, {1,0}};
    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (row<0 || row >= grid.size() || col<0 || col>= grid[0].size() ||
         grid[row][col]=='0') {
            return;
         }
         grid[row][col] = '0';
         for (int i = 0; i < 4; i++) {
            dfs(grid, row+dir[i][0], col+dir[i][1]);
         }

    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};