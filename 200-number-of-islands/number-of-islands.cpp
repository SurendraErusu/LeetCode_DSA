class Solution {
public:

    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (row <0 || row >= grid.size() || col<0 || col>= grid[0].size() 
        || grid[row][col] == '0') {
            return;
        }
        grid[row][col] = '0';
        for(int i = 0; i < dir.size(); i++) {
            int r = row+dir[i][0];
            int c = col+dir[i][1];
            dfs(grid, r, c);
        }

    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i<grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};