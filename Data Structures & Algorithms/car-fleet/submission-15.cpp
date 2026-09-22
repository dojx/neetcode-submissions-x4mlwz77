class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        size_t carsCount = position.size();
        vector<int> indices(carsCount);

        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&position](int i, int j) {
            return position[i] > position[j];
        });

        stack<double> fleets;
        for (int i : indices) {
            double time = static_cast<double>(target - position[i]) / speed[i];
            if (fleets.empty() || time > fleets.top()) {
                fleets.push(time);
            }
        }

        return fleets.size();
    }
};