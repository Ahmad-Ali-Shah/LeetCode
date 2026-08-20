int hashTable(char data) {

    if (data == '.') {
        return 0;
    }

    else {
        return (data - '0') % 10;
    }
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // use hash table for that solution

        int array[9][10];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 10; j++) {
                array[i][j] = -1;
            }
        }

        int rowCounter = 0;

        // check rows
        for (int i = 0; i < 9; i++) {

            rowCounter = 0;

            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {
                    continue;
                }

                int value = hashTable(board[i][j]);

                if (array[i][value] == -1) {
                    array[i][value] = value;
                }
                else {
                    // already there
                    return false;
                }
            }
        }

        // reset hash table
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 10; j++) {
                array[i][j] = -1;
            }
        }

        // check columns
        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {

                if (board[j][i] == '.') {
                    continue;
                }

                int value = hashTable(board[j][i]);

                if (array[i][value] == -1) {
                    array[i][value] = value;
                }
                else {
                    // already there
                    return false;
                }
            }
        }

        // reset hash table
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 10; j++) {
                array[i][j] = -1;
            }
        }

        // check 3x3 boxes
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {

            for (int boxCol = 0; boxCol < 9; boxCol += 3) {

                for (int i = boxRow; i < boxRow + 3; i++) {

                    for (int j = boxCol; j < boxCol + 3; j++) {

                        if (board[i][j] == '.') {
                            continue;
                        }

                        int value = hashTable(board[i][j]);

                        if (array[0][value] == -1) {
                            array[0][value] = value;
                        }
                        else {
                            // already there
                            return false;
                        }
                    }
                }

                // reset hash table for next box
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 10; j++) {
                        array[i][j] = -1;
                    }
                }
            }
        }

        return true;
    }
};