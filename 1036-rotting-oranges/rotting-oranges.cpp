class Solution {
public:
    
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int tmax = 0;
        queue<pair<pair<int,int>, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({{i,j}, 0});
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int row = node.first.first;
            int col = node.first.second;
            int t = node.second;
            tmax = max(t,tmax);

            for (int i = 0; i < dir.size(); i++) {
                int nr = row+dir[i][0];
                int nc = col+dir[i][1];
                if (nr<0 || nr>=grid.size() || nc<0 || nc>=grid[0].size() || 
                grid[nr][nc] != 1) {
                    continue;
                }
                grid[nr][nc] = 2;
                q.push({{nr,nc}, t+1});
                fresh--;
            } 
        }
        if (fresh == 0) {
            return tmax;
        }
        return -1;
    }
};