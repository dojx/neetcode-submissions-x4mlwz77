/*
    binary search on first elements of each column
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1, m;
        // find row that could contain
        while (l < r) {
            m = l + (r - l + 1) / 2;
            if (matrix[m][0] == target) return true;
            if (matrix[m][0] < target) {
                l = m;
            } else {
                r = m - 1;
            }
        }

        int row = l;
        l = 0; r = matrix[0].size() - 1;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (matrix[row][m] == target) return true;
            if (matrix[row][m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return false;
    }
};
