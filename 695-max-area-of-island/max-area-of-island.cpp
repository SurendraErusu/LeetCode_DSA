class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int Max_area = 0;
        int count = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    dfs(grid, r, c,count);
                    Max_area = max(Max_area, count);
                    count = 0;
                }
            }
        }
        return Max_area;
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int &count) {
        if (r < 0 || c < 0 || r >= grid.size() ||
            c >= grid[0].size() || grid[r][c] == 0) {
            return ;
        }

        grid[r][c] = 0;
        count++;
        for (int i = 0; i < 4; i++) {
                 dfs(grid, r + directions[i][0], c + directions[i][1], count);
        }
    }
};