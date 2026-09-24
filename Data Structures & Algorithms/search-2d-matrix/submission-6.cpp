class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = (int)matrix.size() - 1, m;
        int row = 0; // default if target is smaller than every row's first element

        while (l <= r) {
            m = l + (r - l) / 2;
            if (matrix[m][0] == target) return true;
            if (matrix[m][0] < target) {
                row = m;      // matrix[m][0] is a valid "row could contain target" candidate
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        int lo = 0, hi = (int)matrix[0].size() - 1;
        while (lo <= hi) {
            m = lo + (hi - lo) / 2;
            if (matrix[row][m] == target) return true;
            if (matrix[row][m] < target) {
                lo = m + 1;
            } else {
                hi = m - 1;
            }
        }

        return false;
    }
};