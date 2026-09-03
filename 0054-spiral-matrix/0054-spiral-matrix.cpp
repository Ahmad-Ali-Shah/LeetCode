class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        // moving via row

        bool isRun = true;

        int counter = 0;

        // we shall describe each and everything earlier

        int rows = matrix.size();
        int cols = matrix[0].size();
        

        int top = 0;
        int bottom = rows - 1;
        int left = 0;
        int right = cols - 1;

        while (isRun) {

            bool isrunningAll = false;

            // moving right
            for (int i = left; i <= right; i++) {

                result.push_back(matrix[top][i]);
                isrunningAll = true;
            }

            //squeze top 

            top++;

            // moving down
            for (int j = top; j <= bottom; j++) {

                result.push_back(matrix[j][right]);
                isrunningAll = true;
            }

            //squeeze right since it never traverse to that path 

            right--;

            // for moving then left
            if (top <= bottom) {
                //in that case top must be < bottem then in that case iit must iterate from right to left 

                for (int j = right; j >= left; j--) {

                    result.push_back(matrix[bottom][j]);
                    isrunningAll = true;
                }

                bottom--;
            }

            // moving up
            if (left <= right) {

                for (int j = bottom; j >= top; j--) {

                    result.push_back(matrix[j][left]);
                    isrunningAll = true;
                }

                left++;
            }

            // increment the counter
            counter++;

            if (!isrunningAll || top > bottom || left > right) {
                isRun = false;
            }
        }

        return result;
    }
};