class Solution {
public:

    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void bfs(vector<vector<char>>& grid, int row, int col) {
        queue<pair<int,int>> q;
        q.push({row, col});
        grid[row][col] = '0';
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            int r = node.first;
            int c = node.second;
            for (int i = 0; i < dir.size(); i++) {
                int nr = r+dir[i][0];
                int nc = c+dir[i][1];
                if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size() 
                || grid[nr][nc] == '0') {
                    continue;
                }
                q.push({nr,nc});
                grid[nr][nc] = '0';
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i<grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};