class Solution {
public:
    vector<vector<int>> dir = {{1,0}, {0,1}, {-1, 0}, {0,-1}};

    void dfs (int r, int c, int &p, vector<vector<int>>& grid) {

        if (r < 0 || r >= grid.size() ||  c < 0 || c >= grid[0].size() 
        || grid[r][c] == 0) {
            p++;
            return;
        }
        if (grid[r][c] == 2) {
            return;
        }
        grid[r][c] = 2;

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            dfs(nr, nc, p, grid);
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int p = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, p, grid);
                }
            }
        }
        return p;
    }
};