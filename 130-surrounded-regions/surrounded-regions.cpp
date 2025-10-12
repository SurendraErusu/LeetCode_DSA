class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<char>>& board, int row, int col) {
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() 
        || board[row][col] != 'O') {
            return;
        }
        board[row][col] = '#';
        for (int i = 0; i < dir.size(); i++) {
            int nr = row+dir[i][0];
            int nc = col+dir[i][1];
            dfs(board, nr, nc);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[n-1][j] == 'O') dfs(board, n-1, j);
        }
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][m-1] == 'O') dfs(board, i, m-1);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j< m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};