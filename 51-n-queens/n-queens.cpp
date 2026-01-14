class Solution {
public:

    bool isSafe(int r, int c, vector<vector<char>> board, int n) {

        for (int j = 0; j < n; j++) {
            if (board[r][j] == 'Q') return false;
        }
         for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = r, j = c; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }

    void helper (int col, int n, vector<vector<char>> &board, vector<vector<string>> &ans) {
        if (col == n) {
            vector<string> temp;
            for (int i = 0; i < n; i++) {
                string row(board[i].begin(), board[i].end());
                temp.push_back(row);
            }
            ans.push_back(temp);
            return;
        }
        
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                helper(col+1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<char>> board(n, vector<char> (n,'.'));
      vector<vector<string>> ans;
      helper(0, n, board, ans);
      return ans;  
    }
};