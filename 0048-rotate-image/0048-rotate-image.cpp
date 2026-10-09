/*
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        double gamma = 90.0 * M_PI / 180.0;

        double cg = cos(gamma);
        double sg = sin(gamma);

        // 90-degree clockwise rotation
        double r00 = 0,  r01 = 1,  r02 = 0;
        double r10 = -1, r11 = 0,  r12 = 0;
        double r20 = 0,  r21 = 0,  r22 = 1;

        // Save original values
        double a = matrix[0][0], b = matrix[0][1], c = matrix[0][2];
        double d = matrix[1][0], e = matrix[1][1], f = matrix[1][2];
        double g = matrix[2][0], h = matrix[2][1], i = matrix[2][2];

        // P' = R * P
        matrix[0][0] = g;
        matrix[0][1] = d;
        matrix[0][2] = a;

        matrix[1][0] = h;
        matrix[1][1] = e;
        matrix[1][2] = b;

        matrix[2][0] = i;
        matrix[2][1] = f;
        matrix[2][2] = c;
    }
};
for rotating a 3x3 matrix 
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // Transpose the matrix
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }


        // but in reality rotation is basically transpose and reverse 

        // Reverse each row
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
