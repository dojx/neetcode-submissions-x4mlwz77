class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9 ; i++) {
            int v1 = 0, v2 = 0, v3 = 0, c;
            int val;

            for (int j = 0; j < 9 ; j++) {
                // rows
                c = board[i][j];
                if (c != '.') {
                    val = c - '0' - 1;
                    if (v1 & (1 << val)) return false;
                    v1 |= (1 << val);
                }

                // cols
                c = board[j][i];
                if (c != '.') {
                    val = c - '0' - 1;
                    if (v2 & (1 << val)) return false;
                    v2 |= (1 << val);
                }

                // rows
                c = board[(3 * (i / 3)) + (j / 3)][(3 * (i % 3)) + (j % 3)];
                if (c != '.') {
                    val = c - '0' - 1;
                    if (v3 & (1 << val)) return false;
                    v3 |= (1 << val);
                }
            }
        }
        return true;
    }
};
