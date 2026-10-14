class Solution {
    unordered_map<int, int> m;
public:
    int climbStairs(int n) {
        if (n < 0) return 0;
        if (n == 0) return 1;
        if (!m.contains(n))
            m[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return m[n];
    }
};
