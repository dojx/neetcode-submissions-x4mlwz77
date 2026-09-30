class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>> q;
        for (int i = 0; i < points.size(); ++i) {
            q.push({distanceFromOrigin(points[i]), i});
            if (q.size() > k) q.pop();
        }

        vector<vector<int>> res;
        while (!q.empty()) {
            res.push_back(points[q.top().second]);
            q.pop();
        }

        return res;
    }

    double distanceFromOrigin(vector<int>& point) {
        return sqrt((point[0] * point[0]) + (point[1] * point[1]));
    } 
};
