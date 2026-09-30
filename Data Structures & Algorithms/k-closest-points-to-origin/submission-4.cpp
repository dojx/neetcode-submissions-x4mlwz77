class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, int>> q;  // {squared distance, index}
        for (int i = 0; i < points.size(); ++i) {
            q.push({squaredDistance(points[i]), i});
            if (q.size() > k) q.pop();
        }

        vector<vector<int>> res;
        while (!q.empty()) {
            res.push_back(points[q.top().second]);
            q.pop();
        }
        return res;
    }

private:
    long long squaredDistance(const vector<int>& p) {
        return (long long)p[0] * p[0] + (long long)p[1] * p[1];
    }
};