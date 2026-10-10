class Solution {
private:
    set<pair<int, int>> visited;
    int res;
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        res = 0;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (grid[i][j] == '1' && !visited.contains({i, j})) {
                    q.push({i, j});
                    while (!q.empty()) {
                        auto p = q.front(); q.pop();
                        if (p.first < 0 || p.first >= ROWS || p.second < 0 || p.second >= COLS) continue;
                        if (grid[p.first][p.second] == '0' || visited.contains(p)) continue;
                        visited.insert(p);
                        q.push({p.first - 1, p.second});
                        q.push({p.first + 1, p.second});
                        q.push({p.first, p.second - 1});
                        q.push({p.first, p.second + 1});
                    }
                    res++;
                }
            }
        }
        return res;
    }

};
