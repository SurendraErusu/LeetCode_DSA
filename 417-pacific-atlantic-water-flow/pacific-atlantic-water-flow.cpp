
class Solution {
    int ROWS, COLS;
    vector<vector<int>> dr = {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(int r, int c, set<pair<int,int>> &vis,
             vector<vector<int>> &heights, int prevHeight) {

        if (r < 0 || c < 0 || r >= ROWS || c >= COLS ||
            vis.count({r, c}) || heights[r][c] < prevHeight)
            return;

        vis.insert({r, c});

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i][0];
            int nc = c + dr[i][1];
            dfs(nr, nc, vis, heights, heights[r][c]);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = (int)heights.size();
        COLS = (int)heights[0].size();

        set<pair<int,int>> pac, atl;

        // start from borders
        for (int c = 0; c < COLS; c++) {
            dfs(0, c, pac, heights, heights[0][c]);                 // top -> pac
            dfs(ROWS - 1, c, atl, heights, heights[ROWS - 1][c]);   // bottom -> atl
        }
        for (int r = 0; r < ROWS; r++) {
            dfs(r, 0, pac, heights, heights[r][0]);                 // left -> pac
            dfs(r, COLS - 1, atl, heights, heights[r][COLS - 1]);   // right -> atl
        }

        vector<vector<int>> res;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (pac.count({r, c}) && atl.count({r, c})) {
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }
};
