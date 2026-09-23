class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        size_t numCount = numbers.size();
        int a = 0, b = numCount - 1;

        while (a < b) {
            int c = numbers[a] + numbers[b];
            if (c == target) {
                return {a + 1, b + 1};
            }
            if (c < target) {
                a++;
            } else {
                b--;
            }
        }

        return {};
    }
};
