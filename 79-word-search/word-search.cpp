class Solution {
public:

    bool helper (int r, int c, int i, vector<vector<char>>& board, string word) {
        if (i == word.size()) {
            return true;
        }
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || 
        board[r][c] == '#' || board[r][c] != word[i]) {
            return false;
        }
        board[r][c] = '#';
        bool res =  helper(r+1, c, i+1, board, word) ||
                    helper(r-1, c, i+1, board, word) ||
                    helper(r, c+1, i+1, board, word) ||
                    helper(r, c-1, i+1, board, word);
        board[r][c] = word[i];
        return res;

    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                    if (helper(i, j, 0, board, word)) {
                        return true;
                    }
            }
        }
        return false;
    }
};