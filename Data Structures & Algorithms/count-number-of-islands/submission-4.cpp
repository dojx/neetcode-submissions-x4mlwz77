class Solution {
private:
    set<pair<int, int>> visited;
    int res;
public:
    int numIslands(vector<vector<char>>& grid) {
        res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1' && !visited.contains({i, j})) {
                    helper(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }

    void helper(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if (grid[i][j] == '0' || visited.contains({i, j})) return;
        visited.insert({i, j});
        helper(grid, i - 1, j);
        helper(grid, i + 1, j);
        helper(grid, i, j - 1);
        helper(grid, i, j + 1);
    }

};
