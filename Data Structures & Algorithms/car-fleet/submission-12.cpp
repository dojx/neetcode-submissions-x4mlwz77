class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int> cars;
        for (int i = 0; i < position.size(); i++) {
            cars[position[i]] = speed[i];
        }
        stack<double> arrivalTimes;
        for (auto& pair : cars) {
            double arrivalTime = static_cast<double>(target - pair.first) / pair.second;
            arrivalTimes.push(arrivalTime);
        }
        int ans = 0;
        while (!arrivalTimes.empty())
        {
            double leader = arrivalTimes.top();
            arrivalTimes.pop();
            while (!arrivalTimes.empty() && leader >= arrivalTimes.top())
            {
                arrivalTimes.pop();
            }
            
            ans++;
        }
        return ans;
    }
};
