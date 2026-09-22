class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk = {};
        vector<int> res(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); ++i) {
            if (i == 0) {
                stk.push(i);
                continue;
            }
                
            while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                res[stk.top()] = i - stk.top();
                stk.pop();
            } 
            stk.push(i);
        }
        
        return res;
    }
};
