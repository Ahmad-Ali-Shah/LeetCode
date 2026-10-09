
class Solution {

    bool isValid(vector<string>& board, int rows, int cols) {

        int n = board.size();

        // check column
        for(int i = 0; i < rows; i++) {
            if(board[i][cols] == 'Q') {
                return false;
            }
        }

        // check diagonal: top-left
        for(int i = rows - 1, j = cols - 1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }

        // check diagonal: top-right
        for(int i = rows - 1, j = cols + 1;i >= 0 && j < n; i--, j++) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void solve(vector<vector<string>>& output,  vector<string>& board, int rows, int n) {

        // base case
        if(rows == n) {
            output.push_back(board);
            return;
        }

        for(int i = 0; i < n; i++) {

            if(isValid(board, rows, i)) {

                board[rows][i] = 'Q';

                solve(output, board, rows + 1, n);

                // backtrack
                board[rows][i] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> output;

        // first initialize the entire board with dots
        vector<string> board(n, string(n, '.'));

        // start solving from row 0
        solve(output, board, 0, n);

        return output;
    }
};
