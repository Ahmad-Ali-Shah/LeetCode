class Solution {

    bool checkAll(vector<vector<char>>& board, char value,
                  int pointX, int pointY) {

        // 1) Check row
        for (int i = 0; i < 9; i++) {
            if (i != pointY && board[pointX][i] == value)
                return false;
        }

        // 2) Check column
        for (int i = 0; i < 9; i++) {
            if (i != pointX && board[i][pointY] == value)
                return false;
        }

        // 3) Check 3x3 box
        int startX = (pointX / 3) * 3;
        int startY = (pointY / 3) * 3;

        for (int i = startX; i < startX + 3; i++) {
            for (int j = startY; j < startY + 3; j++) {
                if ((i != pointX || j != pointY) &&
                    board[i][j] == value)
                    return false;
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {

        // Find an empty cell
        for (int rows = 0; rows < 9; rows++) {
            for (int cols = 0; cols < 9; cols++) {

                if (board[rows][cols] == '.') {

                    // Try digits 1 to 9
                    for (char value = '1'; value <= '9'; value++) {

                        if (checkAll(board, value, rows, cols)) {

                            // Choose
                            board[rows][cols] = value;

                            // Recursion
                            solveSudoku(board);

                            
                            bool solved = true;

                            for (int i = 0; i < 9; i++) {
                                for (int j = 0; j < 9; j++) {
                                    if (board[i][j] == '.') {
                                        solved = false;
                                        break;
                                    }
                                }
                                if (!solved) break;
                            }

                            if (solved)
                             return;

                            // Backtrack
                            board[rows][cols] = '.';
                        }
                    }

                    // No digit worked for this empty cell
                    return;
                }
            }
        }
    }
};