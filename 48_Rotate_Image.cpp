class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n ; i++)  {
            for (int j = 0;  j < n / 2; j++)  {
                swap(matrix[i][j], matrix[i][ n - (j + 1)]);
            }
        }
        int i = 0, j = 0;
        for (int i = 0;  i < n - j; i++)  {
            for (int j = 0; j < n - i; j++)  {
                if ((i + j) != (n - 1))
                    swap(matrix[j][i], matrix[n - 1 - i][n - 1 - j]);
            }
        }
    }
};
