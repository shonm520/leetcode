/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
For example,
Given the following matrix:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int> > dirs{ { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };    //四个方向，→↓←↑（x,y）的步增
        vector<int> res;
        
        int nr = matrix.size();     if (nr == 0) return res;
        int nc = matrix[0].size();  if (nc == 0) return res;

        vector<int> nSteps{ nc, nr - 1 };

        int iDir = 0;           // index of direction.
        int ir = 0, ic = -1;    // initial position
        while (nSteps[iDir % 2]) {
            for (int i = 0; i < nSteps[iDir % 2]; ++i) {
                ir += dirs[iDir][0]; ic += dirs[iDir][1];
                res.push_back(matrix[ir][ic]);
            }
            nSteps[iDir % 2]--;
            iDir = (iDir + 1) % 4;
        }
        return res;
    }
};
