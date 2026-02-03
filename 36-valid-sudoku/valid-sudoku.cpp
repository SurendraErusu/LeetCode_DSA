class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>> row, col;
        map<pair<int,int>, unordered_set<char>> square;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                pair<int,int> key = {i/3, j/3};
                if (board[i][j] == '.') {
                    continue;
                }
                if (row[i].count(board[i][j]) 
                || col[j].count(board[i][j]) 
                || square[key].count(board[i][j])) {
                    return false;
                }
                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                square[key].insert(board[i][j]);
            }
        }
        return true;
    }
};
